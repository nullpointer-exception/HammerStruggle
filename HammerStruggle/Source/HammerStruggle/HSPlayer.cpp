#pragma region project include
#include "HSPlayer.h"
#pragma endregion

#pragma region UE4 include
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#pragma endregion

#pragma region constructor
// constructor
AHSPlayer::AHSPlayer()
{
	// enable update every frame
	PrimaryActorTick.bCanEverTick = true;

	// create root default scene component and make root
	USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = pRoot;

	// create default capsule component and attach to root
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(pRoot);

	// create default static mesh component and attach to capsule
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);
	Mesh->SetIsReplicated(true);

	// create default scene component and attach to capsule
	CameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraRoot"));
	CameraRoot->SetupAttachment(Capsule);

	// create default camera component and attach to camera root
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraRoot);

	// create default scene component and attach to camera root
	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(CameraRoot);

	// replicate player
	bReplicates = true;

	// add player tag
	Tags.Add("Player");
}
#pragma endregion

#pragma region public override function
// update every frame
void AHSPlayer::Tick(float DeltaTime)
{
	// parent update every frame
	Super::Tick(DeltaTime);
}
#pragma endregion

#pragma region UFUNCTION
// rotate capusle
void AHSPlayer::Rotate(float LeftRight, float UpDown)
{
	// add rotation left and right of capsule
	Capsule->AddWorldRotation(FRotator(0.0f, LeftRight * RotationSpeed * GetWorld()->GetDeltaSeconds(), 0.0f));

	// calculate angle for up and down angle
	float angle = CameraRoot->GetComponentRotation().Pitch + UpDown * RotationSpeed * GetWorld()->GetDeltaSeconds();
	angle = FMath::Max(-45.0f, FMath::Min(45.0f, angle));

	// set world rotation of camera root by angle
	CameraRoot->SetWorldRotation(FRotator(angle, CameraRoot->GetComponentRotation().Yaw, 0.0f));
}

// move capsule
void AHSPlayer::Move(float LeftRight, float ForwardBack)
{
	// calculate movement to move to by input
	FVector movement = Capsule->GetForwardVector() * MovementSpeed * ForwardBack * GetWorld()->GetDeltaSeconds();
	movement += Capsule->GetRightVector() * MovementSpeed * LeftRight * GetWorld()->GetDeltaSeconds();

	// try to add world offset
	Capsule->AddWorldOffset(movement, true);
}

// attack
void AHSPlayer::Attack()
{
	StartMelee();
}

// weapon collide
void AHSPlayer::Collide(AActor* OtherActor)
{}

// stop melee animation
void AHSPlayer::StopMelee()
{
	// set melee hit false
	m_meleeHit = false;
}

#pragma region protected override function
// called at begin play
void AHSPlayer::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();
}
#pragma endregion

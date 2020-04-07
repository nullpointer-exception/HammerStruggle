// Fill out your copyright notice in the Description page of Project Settings.

#pragma region project include
#include "HSPlayer.h"
#pragma endregion

#pragma region UE4 include
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#pragma endregion

#pragma region constructor
// constructor
AHSPlayer::AHSPlayer()
{
	// enable update every frame
	PrimaryActorTick.bCanEverTick = true;

	// create root default scene component and make root
	//USceneComponent* pRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//RootComponent = pRoot;

	// create default capsule component and attach to root
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	//Capsule->SetupAttachment(pRoot);
	Capsule->InitCapsuleSize(42.f, 68.0f);

	// create default skelatel mesh component and attach to capsule
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);
	Mesh->SetIsReplicated(true);

	// don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// create default instanced static mesh component and attach to mesh
	Weapon = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WeaponInStanby"));
	Weapon->SetupAttachment(Mesh);

	// create default instanced static mesh component and attach to mesh
	Shield = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ShieldInStanby"));
	Shield->SetupAttachment(Mesh);

	// create default arrow component and attach to capsule
	MovementDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("MovementDirection"));
	MovementDirection->SetupAttachment(Capsule);

	// create default scene component and attach to movement direction
	CameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraRoot"));
	CameraRoot->SetupAttachment(MovementDirection);

	// create default springarm component and attach to camera root
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(CameraRoot);
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// create default camera component and attach to camera boom
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

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
// rotate camera
void AHSPlayer::Rotate(float LeftRight)
{
	// add rotation left and right of capsule
	MovementDirection->AddWorldRotation(FRotator(0.0f, LeftRight * RotationSpeed * GetWorld()->GetDeltaSeconds(), 0.0f));
}

// move capsule
void AHSPlayer::Move(float LeftRight, float ForwardBack)
{
	// calculate movement to move to by input
	FVector movement = MovementDirection->GetForwardVector() * MovementSpeed * ForwardBack * GetWorld()->GetDeltaSeconds();
	movement += MovementDirection->GetRightVector() * MovementSpeed * LeftRight * GetWorld()->GetDeltaSeconds();

	// try to add world offset
	Capsule->AddWorldOffset(movement, true);
}

// attack
void AHSPlayer::Attack()
{
	// start melee animation
	StartMelee();
}

// stop melee animation
void AHSPlayer::StopMelee()
{
	// set melee hit false
	m_meleeHit = false;
}
#pragma endregion

#pragma region protected override function
// called at begin play
void AHSPlayer::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();
}
#pragma endregion

// Fill out your copyright notice in the Description page of Project Settings.

#pragma region project include
#include "HSPlayer.h"
#pragma endregion

#pragma region UE4 include
#include "Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h" 
#pragma endregion

#pragma region constructor
// constructor
AHSPlayer::AHSPlayer()
{
	// enable update every frame
	PrimaryActorTick.bCanEverTick = true;

	// create default capsule component and make root
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	Capsule->InitCapsuleSize(42.f, 68.0f);

	// create default skelatel mesh component and attach to capsule
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);
	Mesh->SetIsReplicated(true);

	// don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// create default scene component and attach to mesh bone
	ContainerWeaponHand = CreateDefaultSubobject<USceneComponent>(TEXT("ContainerWeaponHand"));
	ContainerWeaponHand->SetupAttachment(Mesh, "WeaponHand");

	// create default scene component and attach to mesh bone
	ContainerWeaponBelt = CreateDefaultSubobject<USceneComponent>(TEXT("ContainerWeaponBelt"));
	ContainerWeaponBelt->SetupAttachment(Mesh, "WeaponBack");

	// create default instanced static mesh component and attach to container weapon belt
	Weapon = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WeaponInStanby"));
	Weapon->SetupAttachment(ContainerWeaponBelt);

	// create default scene component and attach to mesh bone
	ContainerShieldHand = CreateDefaultSubobject<USceneComponent>(TEXT("ContainerShieldHand"));
	ContainerShieldHand->SetupAttachment(Mesh, "ShieldHand");

	// create default scene component and attach to mesh bone
	ContainerShieldBack = CreateDefaultSubobject<USceneComponent>(TEXT("ContainerShieldBack"));
	ContainerShieldBack->SetupAttachment(Mesh, "ShieldBack");

	// create default instanced static mesh component and attach to container shield back
	Shield = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ShieldInStanby"));
	Shield->SetupAttachment(ContainerShieldBack);

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

// move capsule and rotate mesh
void AHSPlayer::Move(float LeftRight, float ForwardBack)
{

	// calculate movement to move to by input
	Movement = MovementDirection->GetForwardVector() * ForwardBack;
	Movement += MovementDirection->GetRightVector() * LeftRight;

	//Normalize
	Movement.Normalize();

	//Add MovementSpeed
	Movement = Movement * MovementSpeed;

	// try to add world offset
	Capsule->AddWorldOffset(Movement * GetWorld()->GetDeltaSeconds(), true);

	// rotate mesh 
	if (Movement.SizeSquared() > 0.1f)
	{
		// calculate rotation to rotate to by input 
		FRotator rotation = UKismetMathLibrary::MakeRotFromX(Movement);
		// try to add relative rotation
		Mesh->SetRelativeRotation(rotation);
	}
}

// change weapon attachment 
void AHSPlayer::ChangeAttachment(bool IsBlacksmith)
{
	if (IsBlacksmith == true) // change to idle when in Blacksmith
	{
		Shield->AttachToComponent(ContainerShieldBack, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		Weapon->AttachToComponent(ContainerWeaponBelt, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	if (IsBlacksmith == false) // change to fighting when in arena
	{
		Shield->AttachToComponent(ContainerShieldHand, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		Weapon->AttachToComponent(ContainerWeaponHand, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
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

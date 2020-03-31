// Fill out your copyright notice in the Description page of Project Settings.


#include "HSPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#pragma endregion

// Sets default values
AHSPlayer::AHSPlayer()
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(pRoot);
	Capsule->InitCapsuleSize(42.f, 96.0f);

	//ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	//ArrowComponent->SetupAttachment(Capsule);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// create default scene component and attach to capsule
	CameraRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CameraRoot"));
	CameraRoot->SetupAttachment(Capsule);

	// create default camera component and attach to camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(CameraRoot);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SetRelativeRotation(FRotator(-30.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// create default camera component and attach to camera boom
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	// replicate player
	bReplicates = true;

}

// Called to bind functionality to input
void AHSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

#pragma region UFUNCTION
// rotate capusle
void AHSPlayer::Rotate(float LeftRight)
{
	// add rotation left and right of capsule
	Capsule->AddWorldRotation(FRotator(0.0f, LeftRight * RotationSpeed * GetWorld()->GetDeltaSeconds(), 0.0f));

	// calculate angle for up and down angle
	//float angle = CameraRoot->GetComponentRotation().Pitch + UpDown * RotationSpeed * GetWorld()->GetDeltaSeconds();
	//angle = FMath::Max(-45.0f, FMath::Min(45.0f, angle));
	//
	//// set world rotation of camera root by angle
	//CameraRoot->SetWorldRotation(FRotator(angle, CameraRoot->GetComponentRotation().Yaw, 0.0f));
}

void AHSPlayer::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AHSPlayer::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}



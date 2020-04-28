// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#pragma endregion

#pragma region project include
#include "HSPlayer.generated.h"
#pragma endregion

#pragma region forward decleration
class USceneComponent;
class UCapsuleComponent;
class UCameraComponent;
class USpringArmComponent;
class UArrowComponent;
class UInstancedStaticMeshComponent;
#pragma endregion

UCLASS()
/// <summary>
/// player pawn class
/// </summary>
class HAMMERSTRUGGLE_API AHSPlayer : public APawn
{
	GENERATED_BODY()

public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	AHSPlayer();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame	
	/// </summary>
	/// <param name="DeltaTime">time since last frame</param>
	virtual void Tick(float DeltaTime) override;
#pragma endregion

#pragma region UPROPERTY
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Player")
		/// <summary>
		/// rotation speed in angle per second
		/// </summary>
		float RotationSpeed = 180.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Player")
		/// <summary>
		/// movement speed in cm per second
		/// </summary>
		float MovementSpeed = 600.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Player")
		/// <summary>
		/// currend movement speed in cm per second
		/// </summary>
		FVector Movement = FVector();

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// capsule component for collision detection
		/// </summary>
		UCapsuleComponent* Capsule = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// arrow component for movement direction
		/// </summary>
		UArrowComponent* MovementDirection = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// skeltal mesh component for visuals
		/// </summary>
		USkeletalMeshComponent* Mesh = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// scene component for attachment
		/// </summary>
		USceneComponent* ContainerWeaponHand = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// scene component for attachment
		/// </summary>
		USceneComponent* ContainerWeaponBelt = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// scene component for attachment
		/// </summary>
		USceneComponent* ContainerShieldHand = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// scene component for attachment
		/// </summary>
		USceneComponent* ContainerShieldBack = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// instanced static mesh for weapon
		/// </summary>
		UInstancedStaticMeshComponent* Weapon = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Player")
		/// <summary>
		/// instanced static mesh for shield
		/// </summary>
		UInstancedStaticMeshComponent* Shield = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// scene component for camera rotation
		/// </summary>
		USceneComponent* CameraRoot = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// spring arm component for fixed camera distance
		/// </summary>
		USpringArmComponent* CameraBoom = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// camera component
		/// </summary>
		UCameraComponent* Camera = nullptr;
#pragma endregion

#pragma region UFUNCTION
	UFUNCTION(BlueprintImplementableEvent, Category = "Player")
		/// <summary>
		/// start melee attack animation
		/// </summary>
		void StartMelee();

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// rotate capusle
		/// </summary>
		/// <param name="LeftRight">rotation left and right</param>
		void Rotate(float LeftRight);

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// move capsule
		/// </summary>
		/// <param name="LeftRight">left and right movement</param>
		/// <param name="ForwardBack">forward and back movement</param>
		void Move(float LeftRight, float ForwardBack);

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// change weapon attachment
		/// </summary>
		/// <param name="IsBlacksmith">change when in blacksmith</param>
		void ChangeAttachment(bool IsBlacksmith);

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// attack
		/// </summary>
		void Attack();

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// stop melee animation
		/// </summary>
		void StopMelee();
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// called at begin play
	/// </summary>
	virtual void BeginPlay() override;
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// melee attack hit an enemy
	/// </summary>
	bool m_meleeHit = false;
#pragma endregion
};
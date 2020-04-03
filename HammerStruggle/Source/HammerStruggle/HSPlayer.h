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
class UCapsuleComponent;
class UCameraComponent;
class USpringArmComponent;
class UArrowComponent;
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
		float MovementSpeed = 300.0f;

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

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// camera root scene component for camera rotation
		/// </summary>
		USceneComponent* CameraRoot = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Player")
		/// <summary>
		/// camera root scene component for camera rotation
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
		/// <param name="UpDown">rotation up and down</param>
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
		/// attack
		/// </summary>
		void Attack();

	//UFUNCTION(BlueprintCallable, Category = "Player")
	//	/// <summary>
	//	/// weapon collide
	//	/// </summary>
	//	/// <param name="OtherActor">other actor that collides with the weapon</param>
	//	void Collide(AActor* OtherActor);

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

#pragma region private variable
	/// <summary>
	/// location to move remote player to
	/// </summary>
	FVector m_locationToMoveTo = FVector();
#pragma endregion
};
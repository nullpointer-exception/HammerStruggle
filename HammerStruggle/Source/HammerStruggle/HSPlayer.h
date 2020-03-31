// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HSPlayer.generated.h"

class USkeletalMeshComponent;
class UArrowComponent;

UCLASS()
class HAMMERSTRUGGLE_API AHSPlayer : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player", meta = (AllowPrivateAccess = "true"))
		USkeletalMeshComponent* Mesh;

	UPROPERTY()
		UArrowComponent* ArrowComponent;

public:
	// Sets default values for this pawn's properties
	AHSPlayer();

protected:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

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

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// weapon collide
		/// </summary>
		/// <param name="OtherActor">other actor that collides with the weapon</param>
		void Collide(AActor* OtherActor);

	UFUNCTION(BlueprintCallable, Category = "Player")
		/// <summary>
		/// stop melee animation
		/// </summary>
		void StopMelee();

#pragma endregion

#pragma region public function
	/// <summary>
	/// decrease health by damage
	/// </summary>
	/// <param name="_damage">damage</param>
	void DecreaseHealth(int _damage);
#pragma endregion

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
	FORCEINLINE class UCapsuleComponent* GetCapsule() const { return Capsule; }
	FORCEINLINE class USkeletalMeshComponent* GetMesh() const { return Mesh; }
	class UArrowComponent* GetArrowComponent() const { return ArrowComponent; }
};

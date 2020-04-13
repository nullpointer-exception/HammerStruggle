// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#pragma endregion

#pragma region project include
#include "HSBlacksmith.generated.h"
#pragma endregion

#pragma region forward decleration
class UBoxComponent;
#pragma endregion

UCLASS()
class HAMMERSTRUGGLE_API AHSBlacksmith : public AActor
{
	GENERATED_BODY()
	
public:	
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	AHSBlacksmith();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame	
	/// </summary>
	/// <param name="DeltaTime">time since last frame</param>
	virtual void Tick(float DeltaTime) override;
#pragma endregion

#pragma region UPROPERTY
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Blacksmith")
		/// <summary>
		/// box component
		/// </summary>
		UBoxComponent* Room = nullptr;
#pragma endregion

protected:
#pragma region protected override function
	/// <summary>
	/// called at begin play
	/// </summary>
	virtual void BeginPlay() override;
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// is blacksmith
	/// </summary>
	bool m_isBlacksmith = true;
#pragma endregion
};

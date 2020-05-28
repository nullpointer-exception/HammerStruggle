// Fill out your copyright notice in the Description page of Project Settings.
// Bea
#pragma region project include
#include "HSBlacksmith.h"
#include "HSPlayer.h"
#pragma endregion

#pragma region UE4 include
#include "Components/BoxComponent.h"
#pragma endregion

#pragma region constructor
// constructor
AHSBlacksmith::AHSBlacksmith()
{
	// enable update every frame
	PrimaryActorTick.bCanEverTick = true;

	// create default box component and make root
	Room = CreateDefaultSubobject<UBoxComponent>(TEXT("Room"));
	RootComponent = Room;

	// add blacksmith tag
	Tags.Add("Blacksmith");
}
#pragma endregion

#pragma region public override function
// update every frame
void AHSBlacksmith::Tick(float DeltaTime)
{
	// parent update every frame
	Super::Tick(DeltaTime);
}
#pragma endregion

#pragma region protected override function
// called at begin play
void AHSBlacksmith::BeginPlay()
{
	// parent begin play
	Super::BeginPlay();
}
#pragma endregion

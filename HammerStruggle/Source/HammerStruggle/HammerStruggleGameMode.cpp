// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
// Bea
#include "HammerStruggleGameMode.h"
#include "HSPlayer.h"
#include "UObject/ConstructorHelpers.h"

AHammerStruggleGameMode::AHammerStruggleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/PC/Blueprints/BP_HSPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

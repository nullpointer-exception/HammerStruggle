// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
// Bea
using UnrealBuildTool;

public class HammerStruggle : ModuleRules
{
	public HammerStruggle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

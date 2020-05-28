// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
// Bea
using UnrealBuildTool;
using System.Collections.Generic;

public class HammerStruggleTarget : TargetRules
{
	public HammerStruggleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("HammerStruggle");
	}
}

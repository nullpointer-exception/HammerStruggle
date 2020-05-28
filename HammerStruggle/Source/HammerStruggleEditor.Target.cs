// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
// Bea
using UnrealBuildTool;
using System.Collections.Generic;

public class HammerStruggleEditorTarget : TargetRules
{
	public HammerStruggleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("HammerStruggle");
	}
}

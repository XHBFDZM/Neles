// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project_Neles : ModuleRules
{
	public Project_Neles(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

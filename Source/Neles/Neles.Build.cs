// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Neles : ModuleRules
{
	public Neles(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Neles",
			"Neles/Variant_Platforming",
			"Neles/Variant_Platforming/Animation",
			"Neles/Variant_Combat",
			"Neles/Variant_Combat/AI",
			"Neles/Variant_Combat/Animation",
			"Neles/Variant_Combat/Gameplay",
			"Neles/Variant_Combat/Interfaces",
			"Neles/Variant_Combat/UI",
			"Neles/Variant_SideScrolling",
			"Neles/Variant_SideScrolling/AI",
			"Neles/Variant_SideScrolling/Gameplay",
			"Neles/Variant_SideScrolling/Interfaces",
			"Neles/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

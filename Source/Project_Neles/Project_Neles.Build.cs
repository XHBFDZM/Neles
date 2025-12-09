// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project_Neles : ModuleRules
{
	public Project_Neles(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "EnhancedInput",
                "UMG",                 // UI 框架（HUD、调试界面）
                "Slate",
                "SlateCore",           // Slate UI 底层
                "GameplayTags",        // 标签系统（未来GAS会用到）
                "GameplayTasks",       // AI、任务系统
                "NavigationSystem",    // 如果角色有移动
                "MathCore"
            }
        );

        //状态树
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "StateTreeModule",
                "GameplayTags",
                "ModularGameplay",
                "GameplayStateTreeModule",
            }
        );
        //AI
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "AIModule",              // AI 基础
                "NavigationSystem"       // NavMesh
            }
        );
    }
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class U_Jam : ModuleRules
{
	public U_Jam(ReadOnlyTargetRules Target) : base(Target)
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
			"U_Jam",
			"U_Jam/Variant_Platforming",
			"U_Jam/Variant_Platforming/Animation",
			"U_Jam/Variant_Combat",
			"U_Jam/Variant_Combat/AI",
			"U_Jam/Variant_Combat/Animation",
			"U_Jam/Variant_Combat/Gameplay",
			"U_Jam/Variant_Combat/Interfaces",
			"U_Jam/Variant_Combat/UI",
			"U_Jam/Variant_SideScrolling",
			"U_Jam/Variant_SideScrolling/AI",
			"U_Jam/Variant_SideScrolling/Gameplay",
			"U_Jam/Variant_SideScrolling/Interfaces",
			"U_Jam/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

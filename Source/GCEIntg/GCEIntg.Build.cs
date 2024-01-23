// Copyright (C) 2024 owoDra

using UnrealBuildTool;

public class GCEIntg : ModuleRules
{
	public GCEIntg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[]
            {
                ModuleDirectory,
                ModuleDirectory + "/GCEIntg",
            }
        );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayTags",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GCExt",
                "GEEquip",
            }
        );

        SetupIrisSupport(Target);
    }
}

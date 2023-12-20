// Copyright (C) 2023 owoDra

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
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GCExt",
                "GAEAddon",
            }
        );

        SetupIrisSupport(Target);
    }
}

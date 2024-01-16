// Copyright (C) 2024 owoDra

#include "CharacterRecipe_AddEquipmentManagerComponent.h"

#include "GCEIntgLogs.h"

#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_AddEquipmentManagerComponent)


UCharacterRecipe_AddEquipmentManagerComponent::UCharacterRecipe_AddEquipmentManagerComponent()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;
}


void UCharacterRecipe_AddEquipmentManagerComponent::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	auto* LoadedComponentClass
	{
		ComponentClass.IsNull() ? nullptr :
		ComponentClass.IsValid() ? ComponentClass.Get() : ComponentClass.LoadSynchronous()
	};

	if (ComponentClass)
	{
		auto* NewEMC{ NewObject<UEquipmentManagerComponent>(Pawn, LoadedComponentClass) };
		NewEMC->RegisterComponent();

		UE_LOG(LogGCEI, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewEMC), *GetNameSafe(LoadedComponentClass));

		auto* LoadedEquipmentSet
		{
			EquipmentSet.IsNull() ? nullptr :
			EquipmentSet.IsValid() ? EquipmentSet.Get() : EquipmentSet.LoadSynchronous()
		};

		UE_LOG(LogGCEI, Log, TEXT("++EquipmentSet (Name: %s)"), *GetNameSafe(LoadedEquipmentSet));

		NewEMC->SetInitialEquipmentSet(LoadedEquipmentSet);
	}
}

// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyEquipmentSet.h"

#include "GCEIntgLogs.h"

#include "EquipmentFunctionLibrary.h"
#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyEquipmentSet)


UCharacterRecipe_ApplyEquipmentSet::UCharacterRecipe_ApplyEquipmentSet()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;
}


void UCharacterRecipe_ApplyEquipmentSet::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	if (auto* EMC{ UEquipmentFunctionLibrary::GetEquipmentManagerComponentFromPawn(Pawn) })
	{
		auto* LoadedEquipmentSet
		{
			EquipmentSet.IsNull() ? nullptr :
			EquipmentSet.IsValid() ? EquipmentSet.Get() : EquipmentSet.LoadSynchronous()
		};

		UE_LOG(LogGCEI, Log, TEXT("++EquipmentSet (Name: %s)"), *GetNameSafe(LoadedEquipmentSet));

		EMC->SetInitialEquipmentSet(LoadedEquipmentSet);
	}
}

// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyEquipmentSet.h"

#include "EquipmentFunctionLibrary.h"
#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "CharacterInitStateComponent.h"
#include "GCExtLogs.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyEquipmentSet)


UCharacterRecipe_ApplyEquipmentSet::UCharacterRecipe_ApplyEquipmentSet()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;

#if WITH_EDITOR
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("InstancingPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("NetExecutionPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
#endif
}


void UCharacterRecipe_ApplyEquipmentSet::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	if (auto* EMC{ UEquipmentFunctionLibrary::GetEquipmentManagerComponentFromActor(Pawn) })
	{
		auto* LoadedEquipmentSet
		{
			EquipmentSet.IsNull() ? nullptr :
			EquipmentSet.IsValid() ? EquipmentSet.Get() : EquipmentSet.LoadSynchronous()
		};

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++EquipmentSet (Name: %s)"), *GetNameSafe(LoadedEquipmentSet));

		TArray<FActiveEquipmentHandle> DummyHandles;
		LoadedEquipmentSet->AddEquipmentItems(EMC, DummyHandles);
	}
}

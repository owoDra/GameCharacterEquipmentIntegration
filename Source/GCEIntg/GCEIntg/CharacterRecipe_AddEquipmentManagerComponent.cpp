// Copyright (C) 2024 owoDra

#include "CharacterRecipe_AddEquipmentManagerComponent.h"

#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "CharacterInitStateComponent.h"
#include "GCExtLogs.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_AddEquipmentManagerComponent)


UCharacterRecipe_AddEquipmentManagerComponent::UCharacterRecipe_AddEquipmentManagerComponent()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ServerOnly;

#if WITH_EDITOR
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("InstancingPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("NetExecutionPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
#endif
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

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewEMC), *GetNameSafe(LoadedComponentClass));

		auto* LoadedEquipmentSet
		{
			EquipmentSet.IsNull() ? nullptr :
			EquipmentSet.IsValid() ? EquipmentSet.Get() : EquipmentSet.LoadSynchronous()
		};

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++EquipmentSet (Name: %s)"), *GetNameSafe(LoadedEquipmentSet));

		TArray<FActiveEquipmentHandle> DummyHandles;
		LoadedEquipmentSet->AddEquipmentItems(NewEMC, DummyHandles);
	}
}

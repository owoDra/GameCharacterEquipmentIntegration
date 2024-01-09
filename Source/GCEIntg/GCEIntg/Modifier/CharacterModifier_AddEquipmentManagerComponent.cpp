// Copyright (C) 2024 owoDra

#include "CharacterModifier_AddEquipmentManagerComponent.h"

#include "GCEIntgLogs.h"

#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_AddEquipmentManagerComponent)


UCharacterModifier_AddEquipmentManagerComponent::UCharacterModifier_AddEquipmentManagerComponent()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = false;
	bApplyOnServer = true;
}


bool UCharacterModifier_AddEquipmentManagerComponent::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
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

	return bCanApply;
}

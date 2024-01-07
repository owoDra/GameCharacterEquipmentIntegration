// Copyright (C) 2023 owoDra

#include "CharacterModifier_ApplyEquipmentSet.h"

#include "GCEIntgLogs.h"

#include "EquipmentFunctionLibrary.h"
#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_ApplyEquipmentSet)


UCharacterModifier_ApplyEquipmentSet::UCharacterModifier_ApplyEquipmentSet()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = false;
	bApplyOnServer = true;
}


bool UCharacterModifier_ApplyEquipmentSet::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
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

	return bCanApply;
}

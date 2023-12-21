// Copyright (C) 2023 owoDra

#include "CharacterModifier_ApplyEquipmentSet.h"

#include "GCEIntgLogs.h"

#include "EquipmentFunctionLibrary.h"
#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_ApplyEquipmentSet)


void UCharacterModifier_ApplyEquipmentSet::OnApply(APawn* Pawn) const
{
	check(Pawn)

	UE_LOG(LogGCEI, Log, TEXT("[%s] On Instance Apply(%s)"),
		Pawn->HasAuthority() ? TEXT("SERVER") : TEXT("CLIENT"), *GetNameSafe(this));

	const auto* World{ Pawn->GetWorld() };
	const auto bIsServer{ World->GetNetMode() != NM_Client };

	if (bIsServer)
	{
		if (auto* EMC{ UEquipmentFunctionLibrary::GetEquipmentManagerComponentFromPawn(Pawn) })
		{
			auto* LoadedEquipmentSet
			{
				EquipmentSet.IsNull() ? nullptr :
				EquipmentSet.IsValid() ? EquipmentSet.Get() : EquipmentSet.LoadSynchronous()
			};

			UE_LOG(LogGCEI, Log, TEXT("++EquipmentSet (Name: %s)"), *GetNameSafe(LoadedEquipmentSet));

			EMC->ResetEquipmentsByEquipmentSet(LoadedEquipmentSet);
		}
	}
}

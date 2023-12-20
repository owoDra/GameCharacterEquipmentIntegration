// Copyright (C) 2023 owoDra

#include "CharacterModifier_AddEquipmentManagerComponent.h"

#include "GCEIntgLogs.h"

#include "EquipmentManagerComponent.h"
#include "EquipmentSet.h"

#include "GameFramework/Pawn.h"
#include "Net/UnrealNetwork.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_AddEquipmentManagerComponent)


void UCharacterModifier_AddEquipmentManagerComponent::OnApply(APawn* Pawn) const
{
	check(Pawn)

	UE_LOG(LogGCEI, Log, TEXT("[%s] On Instance Apply(%s)"),
		Pawn->HasAuthority() ? TEXT("SERVER") : TEXT("CLIENT"), *GetNameSafe(this));

	const auto* World{ Pawn->GetWorld() };
	const auto bIsServer{ World->GetNetMode() != NM_Client };

	UE_LOG(LogGCEI, Log, TEXT("Adding components for %s to world %s"), *GetPathNameSafe(Pawn), *World->GetDebugDisplayName());

	if (bIsServer)
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

			NewEMC->ResetEquipmentsByEquipmentSet(LoadedEquipmentSet);
		}
	}
}

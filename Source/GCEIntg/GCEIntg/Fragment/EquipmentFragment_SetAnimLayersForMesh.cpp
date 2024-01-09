// Copyright (C) 2024 owoDra

#include "EquipmentFragment_SetAnimLayersForMesh.h"

#include "EquipmentManagerComponent.h"
#include "EquipmentInstance.h"

#include "CharacterMeshAccessorInterface.h"

#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(EquipmentFragment_SetAnimLayersForMesh)


UEquipmentFragment_SetAnimLayersForMesh::UEquipmentFragment_SetAnimLayersForMesh(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void UEquipmentFragment_SetAnimLayersForMesh::OnActivated(UEquipmentManagerComponent* EMC, UEquipmentInstance* Instance) const
{
	check(Instance);

	auto* Pawn{ Instance->GetPawn<APawn>() };

	for (const auto& KVP : AnimLayerToApply)
	{
		const auto& Tag{ KVP.Key };
		const auto& Class{ KVP.Value };

		if (!Class)
		{
			continue;
		}

		if (auto* Mesh{ ICharacterMeshAccessorInterface::Execute_GetMeshByTag(Pawn, Tag) })
		{
			Mesh->LinkAnimClassLayers(Class);
		}
	}
}

void UEquipmentFragment_SetAnimLayersForMesh::OnDeactivated(UEquipmentManagerComponent* EMC, UEquipmentInstance* Instance) const
{
	check(Instance);

	auto* Pawn{ Instance->GetPawn<APawn>() };

	for (const auto& KVP : AnimLayerToApply)
	{
		const auto& Tag{ KVP.Key };
		const auto& Class{ KVP.Value };

		if (!Class)
		{
			continue;
		}

		if (auto* Mesh{ ICharacterMeshAccessorInterface::Execute_GetMeshByTag(Pawn, Tag) })
		{
			Mesh->UnlinkAnimClassLayers(Class);
		}
	}
}

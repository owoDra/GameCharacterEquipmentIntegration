// Copyright (C) 2024 owoDra

#include "EquipmentFragment_SpawnMeshesForMesh.h"

#include "EquipmentManagerComponent.h"
#include "EquipmentInstance.h"

#include "CharacterMeshAccessorInterface.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(EquipmentFragment_SpawnMeshesForMesh)


UEquipmentFragment_SpawnMeshesForMesh::UEquipmentFragment_SpawnMeshesForMesh(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void UEquipmentFragment_SpawnMeshesForMesh::OnActivated(UEquipmentManagerComponent* EMC, UEquipmentInstance* Instance) const
{
	check(Instance);

	auto* Pawn{ Instance->GetPawn<APawn>() };
	const auto bLocallyControlled{ Pawn->IsLocallyControlled() };

	for (const auto& Entry : ComponentToAdd)
	{
		const auto bCanAdd
		{
			(bLocallyControlled && Entry.bAddToOwner) || (!bLocallyControlled && Entry.bAddToOther)
		};

		if (bCanAdd)
		{
			if (auto * Mesh{ ICharacterMeshAccessorInterface::Execute_GetMeshByTag(Pawn, Entry.MeshTypeTag) })
			{
				Instance->SpawnEquipmentMeshes(Mesh, MeshesToSpawn);
			}
		}
	}
}

void UEquipmentFragment_SpawnMeshesForMesh::OnDeactivated(UEquipmentManagerComponent* EMC, UEquipmentInstance* Instance) const
{
	check(Instance);

	Instance->DestroyEquipmentMeshes();
}

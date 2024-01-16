// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_AddEquipmentManagerComponent.generated.h"

class UEquipmentManagerComponent;
class UEquipmentSet;


/**
 * Modifier class to add equipment manager component to Pawn
 */
UCLASS()
class UCharacterRecipe_AddEquipmentManagerComponent final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_AddEquipmentManagerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddEquipmentManagerComponent")
	TSoftClassPtr<UEquipmentManagerComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddEquipmentManagerComponent")
	TSoftObjectPtr<UEquipmentSet> EquipmentSet{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};

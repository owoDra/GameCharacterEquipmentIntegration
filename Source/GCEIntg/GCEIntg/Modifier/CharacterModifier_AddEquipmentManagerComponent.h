// Copyright (C) 2023 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_AddEquipmentManagerComponent.generated.h"

class UEquipmentManagerComponent;
class UEquipmentSet;


/**
 * Modifier class to add equipment manager component to Pawn
 */
UCLASS(meta = (DisplayName = "CM Add Equipment Manager Component"))
class UCharacterModifier_AddEquipmentManagerComponent final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_AddEquipmentManagerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddEquipmentManagerComponent")
	TSoftClassPtr<UEquipmentManagerComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddEquipmentManagerComponent")
	TSoftObjectPtr<UEquipmentSet> EquipmentSet{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};

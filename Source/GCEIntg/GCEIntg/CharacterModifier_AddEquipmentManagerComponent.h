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
	UCharacterModifier_AddEquipmentManagerComponent() {}

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TSoftClassPtr<UEquipmentManagerComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TSoftObjectPtr<UEquipmentSet> EquipmentSet{ nullptr };

protected:
	virtual void OnApply(APawn* Pawn) const override;

};

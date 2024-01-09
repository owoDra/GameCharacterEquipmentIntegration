// Copyright (C) 2024 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_ApplyEquipmentSet.generated.h"

class UEquipmentSet;


/**
 * Modifier class to apply equipment set to Pawn
 */
UCLASS(meta = (DisplayName = "CM Apply Equipment Set"))
class UCharacterModifier_ApplyEquipmentSet final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_ApplyEquipmentSet();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyEquipmentSet")
	TSoftObjectPtr<UEquipmentSet> EquipmentSet{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};

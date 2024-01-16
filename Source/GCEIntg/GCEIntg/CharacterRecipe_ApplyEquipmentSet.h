// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_ApplyEquipmentSet.generated.h"

class UEquipmentSet;


/**
 * Modifier class to apply equipment set to Pawn
 */
UCLASS()
class UCharacterRecipe_ApplyEquipmentSet final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_ApplyEquipmentSet();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyEquipmentSet")
	TSoftObjectPtr<UEquipmentSet> EquipmentSet{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RPG_Game_Prototype/Crafting/BaseCraftedItem.h"
#include "DACraftedItemsWeapons.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RPG_GAME_PROTOTYPE_API UDACraftedItemsWeapons : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<class UBaseCraftedItem*> meleeCraftedWeaponListBP; 
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "CraftedInventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class RPG_GAME_PROTOTYPE_API UCraftedInventoryItem : public UItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> craftedItemBP;
	
protected:
	virtual void Use(class AMyPlayer* pCharacter) override;
	
};

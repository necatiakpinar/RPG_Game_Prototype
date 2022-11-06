// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RPG_Game_Prototype/Enums.h"
#include "BaseCraftedItem.generated.h"

USTRUCT(BlueprintType)
struct FCraftedItemRequirements
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECraftMaterial craftMaterialType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 quantity;
	
};

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UBaseCraftedItem : public UObject
{
	GENERATED_BODY()
	
public:	
	UBaseCraftedItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canCraftable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCraftedItemRequirements> requirementList;
	
	//TODO: Instead of actor, can i pass ICrafteditem or stuff :D i know interfaces are not allowed but try.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> craftedItem;
	
private:
		UPROPERTY()
		class AMyPlayer* player;
	
		UPROPERTY()
		class UCrafterComponent* crafterComponent;

public:	

	UFUNCTION()
	bool CanCraftedItemCraftable();
};

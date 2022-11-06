// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"


class AMyPlayer;

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();

	UPROPERTY(Transient);
	class UWorld* world; // It required to create particles or stuff !

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item") 
	FText useActionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	UStaticMesh* pickupMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	UTexture2D* thumbnail;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item") 
	FText itemDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (Multiline = true))
	FText itemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float weight;
	
	UPROPERTY() class UInventoryComponent* owningInventory;

public:
	virtual void Use(class AMyPlayer* pCharacter);
	virtual class UWorld* GetWorld() const { return world; };
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AMyPlayer* pCharacter);
		
};

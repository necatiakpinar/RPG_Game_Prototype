// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RPG_Game_Prototype/Enums.h"
#include "DACraftMaterialAttributes.generated.h"

/**
 * 
 */
UCLASS()
class RPG_GAME_PROTOTYPE_API UDACraftMaterialAttributes : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString materialName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ECraftMaterial materialType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Multiline = true))
	FText materialDescription;

};

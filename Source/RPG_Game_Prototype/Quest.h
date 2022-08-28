// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enums.h"
#include "Quest.generated.h"

USTRUCT(BlueprintType)
struct FObjective
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	EObjectiveType teaobjectiveType; 
};

class UBaseObjective;
UCLASS( BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UQuest : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FObjective objective;
};

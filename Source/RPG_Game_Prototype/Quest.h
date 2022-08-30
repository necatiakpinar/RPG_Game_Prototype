// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enums.h"
#include "Items/Item.h"
#include "Quest.generated.h"

class AEnemy;

USTRUCT(BlueprintType)
struct FObjective //Later on, update this FObjective struct...
{
	GENERATED_BODY()
	uint8 objectiveIndex;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		EObjectiveType objectiveType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<AEnemy> enemyType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<UItem> itemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isObjectiveFinished;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 targetAmount;

};

class UBaseObjective;
UCLASS( BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UQuest : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FObjective> objectiveList;
	bool isQuestFinished;


public:
	void InitializeObjectives();
	void UpdateQuest();
	void UpdateObjectives(int objectiveIndex, AEnemy* pEnemy = nullptr, UItem* pItem = nullptr);
	void ObjectiveFinished(int objectiveIndex);
	void QuestFinished();
	
};

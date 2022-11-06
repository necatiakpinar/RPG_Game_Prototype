// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enums.h"
#include "Items/Item.h"
#include "Quest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnObjectiveUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveFinished,int, QuestIndex, int,ObjectivedIndex);

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
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString objectiveDescription;
};

class UBaseObjective;
UCLASS( BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UQuest : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FObjective> objectiveList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int questIndex;

	UPROPERTY(Transient)
	bool isQuestFinished;

public:
	UPROPERTY(BlueprintAssignable)
	FOnObjectiveUpdated OnObjectiveUpdated;
	
	UPROPERTY(BlueprintAssignable)
	FOnObjectiveFinished OnObjectiveFinished;


public:
	void InitializeObjectives();
	void UpdateQuest();
	void UpdateObjectives(int objectiveIndex, AEnemy* pEnemy = nullptr, UItem* pItem = nullptr);

	UFUNCTION(BlueprintCallable)
	FObjective GetObjective(int pObjectiveIndex);
	
	UFUNCTION(BlueprintCallable)
	FString GetObjectiveDescription(int pObjectiveIndex);
	
	void ObjectiveFinished(int pQuestIndex, int pObjectiveIndex);
	void QuestFinished();
	
};

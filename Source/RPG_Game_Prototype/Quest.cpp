// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"
#include <string>
#include "BaseObjective.h"
#include "Enemy.h"
#include "Items/Item.h"
#include "Macros.h"
#include "MyUtils.h"

void UQuest::InitializeObjectives()
{
//	OnObjectiveUpdated.AddDynamic(this, &UQuest::UpdateQuest);
	
	int finishedObjectivesAmount = 0;
	for (int i = 0; i < objectiveList.Num(); ++i)
	{
		objectiveList[i].objectiveIndex = i;
		objectiveList[i].isObjectiveFinished = false; //Later on I will connect this with save system... witch respect to save system it will update itself.
		objectiveList[i].objectiveDescription = FString::FromInt(objectiveList[i].targetAmount);
		if (objectiveList[i].isObjectiveFinished)
			finishedObjectivesAmount++;
		
	}

	if (finishedObjectivesAmount >= objectiveList.Num())
		isQuestFinished = true;
	else
		isQuestFinished = false;
}

void UQuest::UpdateQuest()
{
}

void UQuest::UpdateObjectives(int objectiveIndex, AEnemy* pEnemy, UItem* pItem)
{
	if (objectiveIndex == -1) // Update all of the objectives
	{
		for (int i = 0; i < objectiveList.Num(); ++i)
		{
			if(!objectiveList[i].isObjectiveFinished)
			{
				if (pEnemy != nullptr)
				{
					if (pEnemy->GetClass() == objectiveList[i].enemyType)
					{
						objectiveList[i].targetAmount--;
						objectiveList[i].objectiveDescription = FString::FromInt(objectiveList[i].targetAmount).
						Append(" " + UMyUtils::GetEnumValue((uint8)pEnemy->enemyType,"EEnemyType").ToLower() + " Enemy");
						// print(-1,5.0f,FString::Printf(TEXT("Got you motherfucker! There is %d enemy left to finish this quest!"),
						// 	objectiveList[i].targetAmount));

						if (objectiveList[i].targetAmount <= 0)
							ObjectiveFinished(questIndex,objectiveList[i].objectiveIndex);
						else
						{
							OnObjectiveUpdated.Broadcast();
						}
					}
				}
			}
			
		}
	}
}

FObjective UQuest::GetObjective(int pObjectiveIndex)
{
	if (pObjectiveIndex < 0 || pObjectiveIndex > objectiveList.Num() - 1)
	{
		print(-1,3.0f,TEXT("Objective index is not valid!"));
		return FObjective();
	}
	
	return objectiveList[pObjectiveIndex];
		
}

FString UQuest::GetObjectiveDescription(int pObjectiveIndex)
{
	if (pObjectiveIndex < 0 || pObjectiveIndex > objectiveList.Num() - 1)
	{
		print(-1, 3.0f, TEXT("Objective index is not valid!"));
		return FString();
	}
	
	return objectiveList[pObjectiveIndex].objectiveDescription;
		
}

void UQuest::ObjectiveFinished(int pQuestIndex, int pObjectiveIndex)
{
	int finishedObjectivesAmount = 0;
	for (int i = 0; i < objectiveList.Num(); ++i)
	{
		if (i == pObjectiveIndex)
		{
			objectiveList[i].isObjectiveFinished = true;
			OnObjectiveFinished.Broadcast(pQuestIndex, pObjectiveIndex) ;
		}
	
		if (objectiveList[i].isObjectiveFinished)
			finishedObjectivesAmount++;  // Watch this variable very closely.
		
	}

	if (finishedObjectivesAmount >= objectiveList.Num())
		QuestFinished();
	else
	{
		isQuestFinished = false;
	}
}

void UQuest::QuestFinished()
{
	isQuestFinished = true;
	print(-1,5.0f,"QUEST FINISHED! ");

}

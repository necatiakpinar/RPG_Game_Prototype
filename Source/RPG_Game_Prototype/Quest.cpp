// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"
#include "BaseObjective.h"
#include "Enemy.h"
#include "Items/Item.h"
#include "Macros.h"

void UQuest::InitializeObjectives()
{
	int finishedObjectivesAmount = 0;
	for (int i = 0; i < objectiveList.Num(); ++i)
	{
		objectiveList[i].objectiveIndex = i;
		objectiveList[i].isObjectiveFinished = false; //Later on I will connect this with save system... witch respect to save system it will update itself.
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
				if (pEnemy->GetClass() == objectiveList[i].enemyType)
				{
					objectiveList[i].targetAmount--;
					print(-1,5.0f,FString::Printf(TEXT("Got you motherfucker! There is %d enemy left to finish this quest!"),
						objectiveList[i].targetAmount));

					if (objectiveList[i].targetAmount <= 0)
						ObjectiveFinished(objectiveList[i].objectiveIndex);
				}
			}
			
		}
	}
}

void UQuest::ObjectiveFinished(int objectiveIndex)
{
	int finishedObjectivesAmount = 0;
	for (int i = 0; i < objectiveList.Num(); ++i)
	{
		if (i == objectiveIndex)
			objectiveList[i].isObjectiveFinished = true;
	
		if (objectiveList[i].isObjectiveFinished)
			finishedObjectivesAmount++;  // Watch this variable very closely.
		
	}

	if (finishedObjectivesAmount >= objectiveList.Num())
		QuestFinished();
	else
		isQuestFinished = false;
}

void UQuest::QuestFinished()
{
	isQuestFinished = true;
	print(-1,5.0f,"QUEST FINISHED! ");

}

// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestLogComponent.h"
#include "MyUtils.h"
#include "Items/FoodItem.h"
#include "Quest.h"
#include "Enemy.h"
#include "Items/Item.h"
#include "Blueprint/UserWidget.h"
// Sets default values for this component's properties
UQuestLogComponent::UQuestLogComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UQuestLogComponent::OnComponentCreated()
{
}

// Called when the game starts
void UQuestLogComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeQuests();
	
}

void UQuestLogComponent::InitializeQuests()
{
	if (questList.Num() > 0)
	{
		for (int i = 0; i < questList.Num(); ++i)
		{
			questList[i]->InitializeObjectives();
		}
		
		UpdateQuests(-1); //Update HUD at the beginning!
	}
}

void UQuestLogComponent::UpdateQuests(int objectiveIndex, AEnemy* pEnemy, UItem* pItem) 
{
	for (int i = 0; i < questList.Num(); ++i)
	{
		questList[i]->UpdateObjectives(objectiveIndex,pEnemy,pItem);
		UpdateObjectiveHUD(objectiveIndex);
	}
}

void UQuestLogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


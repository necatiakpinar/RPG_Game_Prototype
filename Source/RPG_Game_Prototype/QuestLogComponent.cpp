// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestLogComponent.h"
#include "MyUtils.h"
#include "Items/FoodItem.h"
#include "Quest.h"
// Sets default values for this component's properties
UQuestLogComponent::UQuestLogComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
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
		activeQuest = questList[0];
		if (activeQuest)
		{
			activeQuest->InitializeObjectives();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Active quest is null!"));
		}
	}
}


void UQuestLogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

EObjectiveType UQuestLogComponent::GetCurrentObjectiveType()
{
	return EObjectiveType::None;
}


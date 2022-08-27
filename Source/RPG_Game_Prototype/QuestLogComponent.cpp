// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestLogComponent.h"

// Sets default values for this component's properties
UQuestLogComponent::UQuestLogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts

void UQuestLogComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeQuests();
	
}

void UQuestLogComponent::InitializeQuests()
{
	
	// if (questList.Num() > 0)
	// {
	// 	activeQuest = questList[0];
	// }
}


// Called every frame

void UQuestLogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

EObjectiveType UQuestLogComponent::GetCurrentObjectiveType()
{
	return EObjectiveType::None;
}


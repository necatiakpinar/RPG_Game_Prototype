// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums.h"
#include "Macros.h"
#include "QuestLogComponent.generated.h"

class UQuest;
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_GAME_PROTOTYPE_API UQuestLogComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestLogComponent();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<UQuest*> questList;
	//TArray<UQuest> questInstanceList;
private:
	 UQuest* activeQuest;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InitializeQuests();
	EObjectiveType GetCurrentObjectiveType();
		
};

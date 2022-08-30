// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Enemy.generated.h"



class AMyPlayer;
UCLASS()
class RPG_GAME_PROTOTYPE_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMyPlayer* player;

private:
	FTimerHandle timerHandler;

public:
	AEnemy();
	virtual void BeginPlay() override;
	virtual void Die() override;

	UFUNCTION(BlueprintCallable)
	void AddToTheQuestComponent();
};

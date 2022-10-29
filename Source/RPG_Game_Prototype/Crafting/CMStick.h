// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CraftMaterial.h"
#include "CMStick.generated.h"

/**
 * 
 */
UCLASS()
class RPG_GAME_PROTOTYPE_API ACMStick : public ACraftMaterial
{
	GENERATED_BODY()


public:
	ACMStick();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "RPG_Game_Prototype/Interfaces/Craftable.h"
#include "BaseMeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseMeleeWeapon : public ABaseWeapon, public ICraftable
{
	GENERATED_BODY()

public:
	ABaseMeleeWeapon();
	virtual void InitializeCraftable() override;
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
};

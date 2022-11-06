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
class RPG_GAME_PROTOTYPE_API ABaseMeleeWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float energyPerHit; //TODO: Create energy in base character. It will decrease after every hit. If there is not hit increase energy to max.
public:
	ABaseMeleeWeapon();
	virtual void InitializeCraftable(class ABaseCharacter* pOwner) override;
	void Hit();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	
};

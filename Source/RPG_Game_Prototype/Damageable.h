// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damageable.generated.h"


UINTERFACE(MinimalAPI)
class  UDamageable: public UInterface
{
	GENERATED_BODY()

};

class RPG_GAME_PROTOTYPE_API IDamageable
{
	GENERATED_BODY()

public:
	virtual void TakeDamage(float pDamageTaken) = 0;
	virtual void Die() = 0;
};
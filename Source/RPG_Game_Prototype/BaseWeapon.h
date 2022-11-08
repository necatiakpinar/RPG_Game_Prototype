// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damageable.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Craftable.h"
#include "Enums.h"
#include "BaseWeapon.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReload);

class ABaseProjectile;
class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseWeapon : public AActor, public ICraftable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponType weaponType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canAttack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * mesh;

public:	
	virtual void InitializeCraftable(ABaseCharacter* pOwner) PURE_VIRTUAL(,);
	virtual bool CanAttack() PURE_VIRTUAL(,return false;);
};

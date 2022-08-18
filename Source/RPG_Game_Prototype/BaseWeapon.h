// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 totalAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 currentAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 magazineCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 currentMagazineAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canShoot;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Shoot();
	void ReloadAmmo();
};

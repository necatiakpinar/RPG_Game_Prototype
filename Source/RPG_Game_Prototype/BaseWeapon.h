// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damageable.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Craftable.h"
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
		int32 totalAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 currentAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 magazineCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 currentMagazineAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float rateOfFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float reloadTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canShoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isReloading;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<ABaseProjectile> projectile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 UStaticMeshComponent * mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		 USceneComponent* muzzleLocation;
		
	FOnReload OnReload;
private:
	FTimerHandle timerHandler;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Shoot(FVector pCrossHairLocation);
	void SpawnProjectile(const FVector& pCrossHairLocation);
	void ReloadAmmo();

	virtual void InitializeCraftable(ABaseCharacter* pOwner) override;
};

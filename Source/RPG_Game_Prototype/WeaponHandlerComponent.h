// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponHandlerComponent.generated.h"


class ABaseWeapon;
class ABaseCharacter;
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_GAME_PROTOTYPE_API UWeaponHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponHandlerComponent();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 capacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray <ABaseWeapon*> weaponList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABaseWeapon* activeWeapon;


private:
	FTimerManager* timerManager;
	FTimerHandle timerHandler;
	UWorld* world;
	ABaseCharacter* owner;
	float test;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
		void SetActiveWeapon(int32 pWeaponIndex);
	UFUNCTION()
		void AssignWeapon(ABaseWeapon* pWeapon);
	UFUNCTION(BlueprintCallable)
		void StartShooting();
	UFUNCTION(BlueprintCallable)
		void StopShooting();
	UFUNCTION(BlueprintCallable)
		void StartReloading();
	UFUNCTION(BlueprintCallable)
		void EndReloading();

	void StartShoot();
	void StopShoot();

	void SetWalkingSpeedToShootingSpeed();
	void SetWalkingSpeedToNormal();
};

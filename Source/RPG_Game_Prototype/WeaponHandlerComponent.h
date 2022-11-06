// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThrowableItem.h"
#include "Components/ActorComponent.h"
#include "WeaponHandlerComponent.generated.h"


class ABaseWeapon;
class ABaseCharacter;
class AThrowableItem;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AThrowableItem> throwableItemBP;!

private:
	FTimerHandle timerHandler;
	UWorld* world;
	ABaseCharacter* owner;
	AThrowableItem* throwableItem;
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
	
	UFUNCTION(BlueprintCallable, Category = "Ranged")
	void StartShooting();
	
	UFUNCTION(BlueprintCallable, Category = "Ranged")
	void StopShooting();
	
	UFUNCTION(BlueprintCallable, Category = "Ranged")
	void StartReloading();
	
	UFUNCTION(BlueprintCallable, Category = "Ranged")
	void EndReloading();

	//TODO: Shooting % Hitting can be merged into only one function. Or it is for ranged, and hitting for melee. Do not change :D
	UFUNCTION(BlueprintCallable, Category = "Melee")
	void StartHitting();
	
	UFUNCTION(BlueprintCallable, Category = "Melee")
	void StopHitting();
	

	UFUNCTION(BlueprintCallable)
	void ThrowThrowableItem();
	
	void StartShoot();
	void StopShoot();
	void SetWalkingSpeedToShootingSpeed();
	void SetWalkingSpeedToHittingSpeed();
	void SetWalkingSpeedToNormal();
	
};

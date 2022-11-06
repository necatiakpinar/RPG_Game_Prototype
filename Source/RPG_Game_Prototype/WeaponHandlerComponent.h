// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThrowableItem.h"
#include "Components/ActorComponent.h"
#include "WeaponHandlerComponent.generated.h"

USTRUCT(BlueprintType)
struct FMeleeWeaponAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FTransform socketRMeleeAxeTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FName socketRMeleeBasicAxeName;
	
};

USTRUCT(BlueprintType)
struct FRangedWeaponAttributes
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FTransform socketRRifleTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FName socketRRifleName;
	
};

UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),
	DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UWeaponHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponHandlerComponent();
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMeleeWeaponAttributes meleeWeaponAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRangedWeaponAttributes rangedWeaponAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 capacity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <class ABaseWeapon*> weaponList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ABaseWeapon* activeWeapon;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AThrowableItem> throwableItemBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	TSubclassOf<class ABaseRangedWeapon> rangedWeaponBP;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	TSubclassOf<class ABaseMeleeWeapon> meleeWeaponBP;
private:
	FTimerHandle timerHandler;
	UWorld* world;
	class ABaseCharacter* owner;
	class AThrowableItem* throwableItem;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

	void InitializeReferences();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void CreateMeleeWeapon();
	
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
	void StartHit();
	void StopHit();
	void SetWalkingSpeedToShootingSpeed();
	void SetWalkingSpeedToHittingSpeed();
	void SetWalkingSpeedToNormal();
	
};

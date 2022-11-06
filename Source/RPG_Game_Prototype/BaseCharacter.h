// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "Damageable.h"
#include "QuestLogComponent.h"
#include "BaseCharacter.generated.h"

class ABaseWeapon;
class UWeaponHandlerComponent;

USTRUCT(BlueprintType)
struct FAttributes
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float health;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float energy;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float movementSpeed;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float shootingMovementSpeed;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float hittingMovementSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Runtime Variables")
		float currentHealth;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Runtime Variables")
		float currentEnergy;
		

	/*	FORCEINLINE FAttributes();

		FORCEINLINE FAttributes::FAttributes()
		{
		}*/
};

USTRUCT(BlueprintType)
struct FAttributesBoolean
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	bool isAttacking;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	bool isReloading;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isWeaponDrawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAiming;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	bool isProning;

};


UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseCharacter : public ACharacter , public IInteractable, public IDamageable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAttributes Attributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAttributesBoolean AttributesBoolean;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	float traceDistance;

public:
	UPROPERTY(EditAnywhere, Category = "Blueprints")
	TSubclassOf<ABaseWeapon> weaponBP;
	
	UPROPERTY(EditAnywhere, Category = "Blueprints")
	TSubclassOf<UWeaponHandlerComponent> weaponHandlerBP;
	
	UPROPERTY(EditAnywhere, Category = "Animations")
	UAnimMontage* ReloadAM;
	
	UPROPERTY(EditAnywhere, Category = "Animations")
	UAnimMontage* HitAxeAM;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FTransform socketRWeaponRifleTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FName socketRWeaponRifleName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FTransform socketRCraftedItemBasicAxeTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sockets")
	FName socketRWeaponMeleeBasicAxeName;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector crossHairLocation;
private:
	UWeaponHandlerComponent* weaponHandler;
protected:
	// Called when the game starts or when spawned
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void InitializeSockets();

	void InitializeAttributes();
	void InitializeWeapons();
	void InitializeComponents();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact() override;
	virtual void TakeDamage(float pTakeDamage) override;
	virtual void Die() override;
	virtual void TraceForward_Implementation();
	void IncreaseEnergy(float pEnergyAmount);
	void DecreaseEnergy(float pEnergyAmount);
	void  SetWalkSpeed(float pWalkSpeed);
	void  PlayReloadAnimation();
};


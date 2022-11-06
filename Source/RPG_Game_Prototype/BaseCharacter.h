// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "Damageable.h"
#include "QuestLogComponent.h"
#include "BaseCharacter.generated.h"

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
	TSubclassOf<class ABaseWeapon> weaponBP;
	
	UPROPERTY(EditAnywhere, Category = "Blueprints")
	TSubclassOf<class ABaseMeleeWeapon> meleeWeapon;
	
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector crossHairLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWeaponHandlerComponent* weaponHandlerComponentImplemented;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class UBaseAnimationComponent* animationComponentImplemented;
	
protected:
	// Called when the game starts or when spawned
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	
	void InitializeAttributes();
	void InitializeComponents();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact() PURE_VIRTUAL(,);
	virtual void TakeDamage(float pTakeDamage) override;
	virtual void Die() override;
	virtual void TraceForward_Implementation();
	void IncreaseEnergy(float pEnergyAmount);
	void DecreaseEnergy(float pEnergyAmount);
	void  SetWalkSpeed(float pWalkSpeed);
	
};


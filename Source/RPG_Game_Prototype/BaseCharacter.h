// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "BaseCharacter.generated.h"

class ABaseWeapon;

UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseCharacter : public ACharacter , public IInteractable 
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction") float traceDistance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health") float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes") bool isProning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes") bool isReloading;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes") bool isShooting;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UWeaponHandlerComponent* weaponHandler;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseWeapon> weaponBP;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InitializeWeapons();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact() override;
	
};

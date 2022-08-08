// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "BaseCharacter.generated.h"

UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseCharacter : public ACharacter , public IInteractable 
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction") float traceDistance;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact() override;



};

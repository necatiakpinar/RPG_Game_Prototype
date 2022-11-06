// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseAnimationComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_GAME_PROTOTYPE_API UBaseAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseAnimationComponent();

	UPROPERTY(EditAnywhere, Category = "Animation Montages")
	UAnimMontage* ReloadAM;
	
	UPROPERTY(EditAnywhere, Category = "Animation Montages")
	UAnimMontage* MeleeAxeHitAM;

private:
	class ABaseCharacter* owner;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	void PlayReloadAnimation();
	void PlayMeleeAxeHitAnimation();
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnimationComponent.h"

#include "BaseCharacter.h"

// Sets default values for this component's properties
UBaseAnimationComponent::UBaseAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
}

void UBaseAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
	owner = Cast<ABaseCharacter>(GetOwner());	
}


void UBaseAnimationComponent::PlayReloadAnimation()
{
	UE_LOG(LogTemp, Warning, TEXT("Reload animation duration = %f"), ReloadAM->GetPlayLength());
	owner->PlayAnimMontage(ReloadAM);
}

void UBaseAnimationComponent::PlayMeleeAxeHitAnimation()
{
	UE_LOG(LogTemp, Warning, TEXT("Melee Axe Hit animation duration = %f"), MeleeAxeHitAM->GetPlayLength());
	owner->PlayAnimMontage(MeleeAxeHitAM);
}


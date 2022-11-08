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
	if (owner)
		animInstance = owner->GetMesh()->GetAnimInstance(); 
	
}

void UBaseAnimationComponent::PlayWeaponAnimation(EWeaponAnimationType pAnimationType)
{
	owner->PlayAnimMontage(weaponAnimationDict.FindRef(pAnimationType));
}

bool UBaseAnimationComponent::IsWeaponAnimMontagePlaying(EWeaponAnimationType pAnimationType)
{
	if (animInstance->Montage_IsPlaying(weaponAnimationDict.FindRef(pAnimationType)))
		return true;
	else
		return false;
}


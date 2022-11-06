// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "BaseAnimationComponent.h"
#include "DrawDebugHelpers.h"
#include "WeaponHandlerComponent.h"
#include "BaseWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	InitializeComponents();
}
// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeAttributes();
}

void  ABaseCharacter::InitializeAttributes()
{
	Attributes.currentHealth = Attributes.health;
	Attributes.currentEnergy = Attributes.energy;
}

void ABaseCharacter::InitializeComponents()
{
	weaponHandlerComponentImplemented = Cast<UWeaponHandlerComponent>(GetComponentByClass(UWeaponHandlerComponent::StaticClass()));
	animationComponentImplemented = Cast<UBaseAnimationComponent>(GetComponentByClass(UBaseAnimationComponent::StaticClass()));
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::TakeDamage(float pDamageTaken)
{
	if (Attributes.currentHealth > 0)
	{
		Attributes.currentHealth -= pDamageTaken;

		if (Attributes.currentHealth <= 0)
			Die();
	}
	
}

void ABaseCharacter::IncreaseEnergy(float pEnergyAmount)
{
	
}

void ABaseCharacter::DecreaseEnergy(float pEnergyAmount)
{
	
}

void ABaseCharacter::Die()
{
	TArray<AActor*> attachedActors;
	GetAttachedActors(attachedActors);
	for (int i = 0; i < attachedActors.Num(); i++)
		attachedActors[i]->Destroy();

	AActor::Destroy();
}

void ABaseCharacter::TraceForward_Implementation()
{
}

void ABaseCharacter::SetWalkSpeed(float pWalkSpeed)
{
	GetCharacterMovement()->MaxWalkSpeed = pWalkSpeed;
}


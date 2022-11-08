// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMeleeWeapon.h"

#include "BaseAnimationComponent.h"
#include "Components/SceneComponent.h"
#include "BaseCharacter.h"
#include "WeaponHandlerComponent.h"
#include "Components/StaticMeshComponent.h"

ABaseMeleeWeapon::ABaseMeleeWeapon()
{
	weaponType = EWeaponType::Melee;
}

void ABaseMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();
	InitializeReferences();
}

void ABaseMeleeWeapon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABaseMeleeWeapon::InitializeReferences()
{
	owner = Cast<ABaseCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

bool ABaseMeleeWeapon::CanAttack()
{
	if (owner != nullptr)
	{
		if (owner->Attributes.currentEnergy >= energyPerHit)
			canAttack = true;
		else
			canAttack = false;
	}	
	return canAttack;
}

void ABaseMeleeWeapon::InitializeCraftable(ABaseCharacter* pOwner)
{
	//Get Melee socket name for melee weapons.
	FMeleeWeaponAttributes meleeWeaponAttributes = owner->weaponHandlerComponentImplemented->meleeWeaponAttributes;
	this->AttachToComponent(pOwner->GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,meleeWeaponAttributes.socketRMeleeBasicAxeName);
	UE_LOG(LogTemp, Warning, TEXT("This weapon is craftable!"));
	//TODO: Add this weapon into weapon list on weapon component!
}

void ABaseMeleeWeapon::Hit()
{
	if (owner != nullptr && !owner->animationComponentImplemented->IsWeaponAnimMontagePlaying(EWeaponAnimationType::HitAxe))
	{
		owner->AttributesBoolean.isAttacking = true;
		owner->DecreaseEnergy(energyPerHit); //Decrease energy
		owner->animationComponentImplemented->PlayWeaponAnimation(EWeaponAnimationType::HitAxe); // Play Animation
	}
	
}

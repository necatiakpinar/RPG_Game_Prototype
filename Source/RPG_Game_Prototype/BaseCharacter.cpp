// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
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
	InitializeSockets();
	
}
// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeAttributes();
	InitializeComponents(); 
	InitializeWeapons();
}

void  ABaseCharacter::InitializeAttributes()
{
	Attributes.currentHealth = Attributes.health;
	Attributes.currentEnergy = Attributes.energy;
}

void ABaseCharacter::InitializeComponents()
{
	weaponHandler = Cast<UWeaponHandlerComponent>(GetComponentByClass(UWeaponHandlerComponent::StaticClass()));

}

void ABaseCharacter::InitializeSockets()
{
	socketRWeaponRifleName = "hand_r_weapon_rifle_socket";
	socketRWeaponRifleTransform = GetMesh()->GetSocketTransform(socketRWeaponRifleName);

	socketRWeaponMeleeBasicAxeName = "hand_r_weapon_melee_axe_socket";
	socketRCraftedItemBasicAxeTransform = GetMesh()->GetSocketTransform(socketRWeaponMeleeBasicAxeName);
}

void ABaseCharacter::InitializeWeapons()
{
	if (weaponBP && weaponHandler)
	{
		ABaseWeapon* weapon = GetWorld()->SpawnActor<ABaseWeapon>(weaponBP, socketRWeaponRifleTransform);
		weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, socketRWeaponRifleName);

		weaponHandler->AssignWeapon(weapon);
		UE_LOG(LogTemp, Warning, TEXT("%d"),weaponHandler->weaponList.Num());
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	UE_LOG(LogTemp, Warning, TEXT("%f"), ReloadAM->GetPlayLength());

}

void ABaseCharacter::Interact()
{

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

void ABaseCharacter::PlayReloadAnimation()
{
	UE_LOG(LogTemp, Warning, TEXT("Reload animation duration = %f"), ReloadAM->GetPlayLength());
	PlayAnimMontage(ReloadAM);
}
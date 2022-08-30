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
}

void ABaseCharacter::InitializeComponents()
{
	weaponHandler = Cast<UWeaponHandlerComponent>(GetComponentByClass(UWeaponHandlerComponent::StaticClass()));

}
void ABaseCharacter::InitializeWeapons()
{
	if (weaponBP && weaponHandler)
	{
		FTransform socketTransform = GetMesh()->GetSocketTransform(FName("hand_r_weapon_socket"));
		ABaseWeapon* weapon = GetWorld()->SpawnActor<ABaseWeapon>(weaponBP, socketTransform);
		weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("hand_r_weapon_socket"));
	
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

void ABaseCharacter::Die()
{
	TArray<AActor*> attachedActors;
	GetAttachedActors(attachedActors);
	for (int i = 0; i < attachedActors.Num(); i++)
		attachedActors[i]->Destroy();

	AActor::Destroy();
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
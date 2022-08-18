// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "DrawDebugHelpers.h"
#include "WeaponHandlerComponent.h"
#include "BaseWeapon.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	weaponHandler = CreateDefaultSubobject<UWeaponHandlerComponent>("WeaponHandler");
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeWeapons();
}

void ABaseCharacter::InitializeWeapons()
{
	if (weaponBP)
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

}

void ABaseCharacter::Interact()
{
}

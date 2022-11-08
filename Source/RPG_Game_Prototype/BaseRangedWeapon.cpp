// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRangedWeapon.h"
#include "BaseProjectile.h"
#include "TimerManager.h"
#include "BaseCharacter.h"
#include "WeaponHandlerComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"


ABaseRangedWeapon::ABaseRangedWeapon()
{
	weaponType = EWeaponType::Ranged;
	muzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	muzzleLocation->SetupAttachment(mesh);
}

void ABaseRangedWeapon::BeginPlay()
{
	Super::BeginPlay();
	currentAmmo = totalAmmo;
	currentMagazineAmmo = magazineCapacity;
	canAttack = true; // Characters can shoot at the beginning.
	isReloading = false;
}

void ABaseRangedWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseRangedWeapon::InitializeReferences()
{
	owner = Cast<ABaseCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ABaseRangedWeapon::Shoot(FVector pCrossHairLocation)
{
	if (canAttack  && currentAmmo > 0 && !isReloading)
	{
		SpawnProjectile(pCrossHairLocation);
		currentAmmo--;
	
		if (currentMagazineAmmo > 0 )
			currentMagazineAmmo--;

		if (currentMagazineAmmo == 0 && currentAmmo > 0)
		{
			isReloading = true;
			canAttack = false;
			OnReload.Broadcast();
			GetWorld()->GetTimerManager().SetTimer(timerHandler,this, &ABaseRangedWeapon::ReloadAmmo, reloadTime, false);
		}
	}
	
	if (currentAmmo == 0)
	{
		canAttack = false;
	}
}

void ABaseRangedWeapon::SpawnProjectile(const FVector& pCrossHairLocation)
{
	FVector spawnLocation = (muzzleLocation) ? muzzleLocation->GetComponentLocation() : FVector(0.0f);
	FRotator spawnRotation = (pCrossHairLocation - spawnLocation).Rotation();
	FActorSpawnParameters actorSpawnParams;
	actorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	ABaseProjectile* spawnedProjectile = GetWorld()->SpawnActor<ABaseProjectile>(projectile, spawnLocation, spawnRotation, actorSpawnParams);
	spawnedProjectile->Initialize(damage);

}

void ABaseRangedWeapon::ReloadAmmo()
{
	if (currentAmmo > magazineCapacity)
		currentMagazineAmmo = magazineCapacity; 
	else
		currentMagazineAmmo = currentAmmo; //Remaining ammo

	canAttack = true;
	isReloading = false;

}

bool ABaseRangedWeapon::CanAttack()
{
	if (currentMagazineAmmo == 0 && currentAmmo > 0)
		canAttack = false;
	else
		canAttack = true;

	return canAttack;
}

void ABaseRangedWeapon::InitializeCraftable(ABaseCharacter* pOwner)
{
	FRangedWeaponAttributes rangedWeaponAttributes = pOwner->weaponHandlerComponentImplemented->rangedWeaponAttributes;
	this->AttachToComponent(pOwner->GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,rangedWeaponAttributes.socketRRifleName);
	UE_LOG(LogTemp, Warning, TEXT("This weapon is craftable!"));
}

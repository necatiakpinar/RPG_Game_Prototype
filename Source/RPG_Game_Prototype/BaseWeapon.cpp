// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "BaseProjectile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetOnlyOwnerSee(true);
	mesh->bCastDynamicShadow = false;
	mesh->CastShadow = false;

	muzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	muzzleLocation->SetupAttachment(mesh);
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	currentAmmo = totalAmmo;
	currentMagazineAmmo = magazineCapacity;
	canShoot = true; // Characters can shoot at the beginning.
	isReloading = false;
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseWeapon::Shoot(FRotator pSpawnRotation)
{
	if (canShoot  && currentAmmo > 0 && !isReloading)
	{
		FRotator spawnRotation = pSpawnRotation;
		FVector spawnLocation = (muzzleLocation) ? muzzleLocation->GetComponentLocation() : FVector(0.0f);

		FActorSpawnParameters actorSpawnParams;
		actorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		
		GetWorld()->SpawnActor<ABaseProjectile>(projectile, spawnLocation, spawnRotation, actorSpawnParams);
			
		currentAmmo--;
		
		if (currentMagazineAmmo > 0 )
			currentMagazineAmmo--;

		if (currentMagazineAmmo == 0 && currentAmmo > 0)
		{
			isReloading = true;
			canShoot = false;
			OnReload.Broadcast();
			GetWorld()->GetTimerManager().SetTimer(timerHandler,this, &ABaseWeapon::ReloadAmmo, reloadTime, false);
		}
	}
	
	if (currentAmmo == 0)
	{
		canShoot = false;
	}

	//UE_LOG(LogTemp, Warning, TEXT("CURRENT AMMO = %d , CURRENT MAGAZINE = %d "), currentAmmo, currentMagazineAmmo);
}

void ABaseWeapon::ReloadAmmo()
{
	if (currentAmmo > magazineCapacity)
		currentMagazineAmmo = magazineCapacity; 
	else
		currentMagazineAmmo = currentAmmo; //Remaining ammo

	canShoot = true;
	isReloading = false;
}


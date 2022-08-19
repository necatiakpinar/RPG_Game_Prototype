// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	currentAmmo = totalAmmo;
	currentMagazineAmmo = magazineCapacity;
	canShoot = true; // Characters can shoot at the beginning.
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::Shoot()
{
	if (canShoot  && currentAmmo > 0)
	{
		currentAmmo--;
		
		if (currentMagazineAmmo > 0 )
			currentMagazineAmmo--;

		if (currentMagazineAmmo == 0 && currentAmmo > 0)
			ReloadAmmo();
	}
	
	if (currentAmmo == 0)
	{
		canShoot = false;
	}

	UE_LOG(LogTemp, Warning, TEXT("CURRENT AMMO = %d , CURRENT MAGAZINE = %d "), currentAmmo, currentMagazineAmmo);
}

void ABaseWeapon::ReloadAmmo()
{
	if (canShoot)
	{
		if (currentAmmo > magazineCapacity)
			currentMagazineAmmo = magazineCapacity; 
		else
			currentMagazineAmmo = currentAmmo; //Remaining ammo
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMeleeWeapon.h"

ABaseMeleeWeapon::ABaseMeleeWeapon()
{
}

void ABaseMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseMeleeWeapon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABaseMeleeWeapon::InitializeCraftable()
{
	UE_LOG(LogTemp, Warning, TEXT("This weapon is craftable!"));
	//TODO: Add this weapon into weapon list on weapon component!
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponHandlerComponent.h"
#include "BaseWeapon.h"

// Sets default values for this component's properties
UWeaponHandlerComponent::UWeaponHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UWeaponHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UWeaponHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponHandlerComponent::SetActiveWeapon(int32 pWeaponIndex)
{
	if (pWeaponIndex > weaponList.Num() - 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Given weapon index is higher than current weapon count!"));
		return;
	}

	activeWeapon = weaponList[pWeaponIndex];
}
void UWeaponHandlerComponent::AssignWeapon(ABaseWeapon* pWeapon)
{
	if (weaponList.Num() < capacity)
		weaponList.Add(pWeapon);

	SetActiveWeapon(0);
}

void UWeaponHandlerComponent::Shoot()
{
	if (activeWeapon)
		activeWeapon->Shoot();

}




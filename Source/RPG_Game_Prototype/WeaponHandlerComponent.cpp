// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponHandlerComponent.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "BaseWeapon.h"
#include "BaseCharacter.h"

// Sets default values for this component's properties
UWeaponHandlerComponent::UWeaponHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	capacity = 1; 
}


// Called when the game starts
void UWeaponHandlerComponent::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();
	owner = Cast<ABaseCharacter>(GetOwner());
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
	{
		weaponList.Add(pWeapon);
		pWeapon->OnReload.AddDynamic(this,&UWeaponHandlerComponent::StartReloading);
	}

	SetActiveWeapon(0);
}

void UWeaponHandlerComponent::StartShooting()
{
	if (activeWeapon)
	{
		world->GetTimerManager().SetTimer(timerHandler, this, &UWeaponHandlerComponent::StartShoot, activeWeapon->rateOfFire, true, 0.0f);
	}
}
void UWeaponHandlerComponent::StopShooting()
{
	world->GetTimerManager().ClearTimer(timerHandler);
	StopShoot();
}


void UWeaponHandlerComponent::StartShoot()
{
	if (activeWeapon)
	{
		if (activeWeapon->canShoot)
		{
			owner->AttributesBoolean.isShooting = true;
			SetWalkingSpeedToShootingSpeed();
			activeWeapon->Shoot();
			UE_LOG(LogTemp, Warning, TEXT("SHOOTING!"));
		}
		else
			owner->AttributesBoolean.isShooting = false;
	}
}

void UWeaponHandlerComponent::StopShoot()
{
	owner->AttributesBoolean.isShooting= false;
	SetWalkingSpeedToNormal();
	world->GetTimerManager().ClearTimer(timerHandler);
}

void UWeaponHandlerComponent::StartReloading()
{
//	UE_LOG(LogTemp, Warning, TEXT("LOKKASPOR"));
	owner->PlayReloadAnimation();
}

void UWeaponHandlerComponent::EndReloading()
{
}

void UWeaponHandlerComponent::SetWalkingSpeedToShootingSpeed()
{
	owner->SetWalkSpeed(owner->Attributes.shootingMovementSpeed);
}

void UWeaponHandlerComponent::SetWalkingSpeedToNormal()
{
	owner->SetWalkSpeed(owner->Attributes.movementSpeed);
}





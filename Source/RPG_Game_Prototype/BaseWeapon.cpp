// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"
#include "BaseProjectile.h"
#include "TimerManager.h"
#include "BaseCharacter.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetOnlyOwnerSee(true);
	mesh->bCastDynamicShadow = false;
	mesh->CastShadow = false;
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	InitializeReferences();
}

void ABaseWeapon::InitializeReferences()
{
	owner = Cast<ABaseCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	weaponHandlerComponent = owner->weaponHandlerComponentImplemented; 
}



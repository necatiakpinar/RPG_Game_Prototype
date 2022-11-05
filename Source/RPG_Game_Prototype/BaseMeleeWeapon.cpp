// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMeleeWeapon.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

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
//
// void ABaseMeleeWeapon::InitializeCraftable(ABaseCharacter* pOwner)
// {
// 	this->AttachToComponent(pOwner->GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,pOwner->socketName);
// 	UE_LOG(LogTemp, Warning, TEXT("This weapon is craftable!"));
// 	//TODO: Add this weapon into weapon list on weapon component!
// }

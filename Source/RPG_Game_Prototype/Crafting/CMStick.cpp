// Fill out your copyright notice in the Description page of Project Settings.


#include "CMStick.h"

ACMStick::ACMStick()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACMStick::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

void ACMStick::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACMStick::Initialize()
{
	//Super::Initialize();
	materialType = ECraftMaterial::Rope;
}

void ACMStick::Collect()
{
	print(-1,3.0f,TEXT("STICK"));
}

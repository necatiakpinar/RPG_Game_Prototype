// Fill out your copyright notice in the Description page of Project Settings.


#include "CMStick.h"

ACMStick::ACMStick()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACMStick::BeginPlay()
{
	Super::BeginPlay();
}

void ACMStick::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


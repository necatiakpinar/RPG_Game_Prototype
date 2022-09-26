// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowableItem.h"
#include "TimerManager.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AThrowableItem::AThrowableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));

	RootComponent = itemMesh;
	lifeTime = 10.0f;
}

// Called when the game starts or when spawned
void AThrowableItem::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandler, this, &AThrowableItem::DestroyObject, lifeTime, false, lifeTime);
}

// Called every frame
void AThrowableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AThrowableItem::LaunchThrowable(FVector pImpulse, FVector pLocation)
{
	SetActorLocation(pLocation);
	itemMesh->AddImpulseAtLocation((pImpulse + FVector(0.0f,0.0f,0.1f))* 10000.0f,pLocation);
}

void AThrowableItem::DestroyObject()
{
	GetWorldTimerManager().ClearTimer(timerHandler);
	Destroy();
}


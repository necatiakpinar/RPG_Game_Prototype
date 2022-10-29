// Fill out your copyright notice in the Description page of Project Settings.


#include "CraftMaterial.h"
#include "Components/BoxComponent.h"
#include  "Components/StaticMeshComponent.h"

// Sets default values
ACraftMaterial::ACraftMaterial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //Maybe i can just make this fella false! //TODO:Come here!

	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	RootComponent = boxComponent;

	meshComponent->SetupAttachment(GetRootComponent());
}

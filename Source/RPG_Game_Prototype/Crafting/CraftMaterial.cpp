// Fill out your copyright notice in the Description page of Project Settings.


#include "CraftMaterial.h"
#include "Components/BoxComponent.h"
#include  "Components/StaticMeshComponent.h"
#include "RPG_Game_Prototype/CrafterComponent.h"
#include "RPG_Game_Prototype/MyPlayer.h"
#include "RPG_Game_Prototype/DataAssets/DACraftMaterialAttributes.h"

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

void ACraftMaterial::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

void ACraftMaterial::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACraftMaterial::Initialize()
{
	if (daMaterialProperties)
	{
		materialAttributes.materialName = daMaterialProperties->materialName;
		materialAttributes.materialType = daMaterialProperties->materialType;
		materialAttributes.materialDescription = daMaterialProperties->materialDescription;
	}

	player = Cast<AMyPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	crafterComponent = player->crafterComponentImplemented;
	
}


void ACraftMaterial::Collect()
{
	print(-1,3.0f,TEXT("Collected"));

	if (crafterComponent)
		crafterComponent->IncreaseMaterialQuantity(materialAttributes.materialType);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "CrafterComponent.h"

#include "Crafting/BaseCraftedItem.h"
#include "Crafting/CraftMaterial.h"
#include "RPG_Game_Prototype/Macros.h"
#include "VisualLogger/VisualLoggerTypes.h"
#include "RPG_Game_Prototype/BaseCharacter.h"
#include "RPG_Game_Prototype/Interfaces/Craftable.h"
#include "RPG_Game_Prototype/DataAssets/DACraftMaterialAttributes.h"


//DEFINE_ENUM_TO_STRING(ECraftMaterial);
//ENUM_RANGE_BY_COUNT(ECraftMaterial,ECraftMaterial::Count);
//TEnumRange<EnumName>()

// Sets default values for this component's properties
UCrafterComponent::UCrafterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCrafterComponent::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

// Called every frame
void UCrafterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCrafterComponent::Initialize()
{
	//Initialize the materials
	for (int i = 0; i < materialDataList.Num(); i++)
	{
		if (materialDataList[0]->materialType == ECraftMaterial::None)
			continue;
		
		UDACraftMaterialAttributes* materialData = materialDataList[i];
		FCraftMaterialProperties materialProperties = FCraftMaterialProperties(materialData->materialName,materialData->materialType, 0);
		materialDict.Add(materialData->materialType,materialProperties);
	}

	//Initialize the references
	owner = Cast<ABaseCharacter>(GetOwner());

	if (craftedItemBP)
	{
		CreateCraftedItem(craftedItemBP);
		// if (craftedItemBP->canCraftable)
		// 	UE_LOG(LogTemp, Warning, TEXT(" GIRDI! %s"), ( craftedItemBP->canCraftable ? TEXT("true") : TEXT("false") ));
	}
}

FCraftMaterialProperties UCrafterComponent::GetCraftMaterialProperties(ECraftMaterial pMaterialType)
{
	return materialDict[pMaterialType];
	
}


void UCrafterComponent::IncreaseMaterialQuantity(ECraftMaterial pMaterialType, int32 pIncreaseAmount)
{
	if (materialDict[pMaterialType].materialType != ECraftMaterial::None) //If material exist
	{
		materialDict[pMaterialType].materialQuantity += pIncreaseAmount;
		OnCrafterMaterialsUpdated.Broadcast();
	}
	
}

void UCrafterComponent::DecreaseMaterialQuantity(ECraftMaterial pMaterialType, int32 pDecreaseAmount)
{
	if (materialDict[pMaterialType].materialType != ECraftMaterial::None) //If material exist
	{
		materialDict[pMaterialType].materialQuantity -= pDecreaseAmount;
		OnCrafterMaterialsUpdated.Broadcast();
	}
	
}

//TODO: I need to create reference to the inventory, right now I'm directly creating the item and giving the players hands
void UCrafterComponent::CreateCraftedItem(UBaseCraftedItem* pBaseCraftedItem)
{
	if (pBaseCraftedItem)
	{
		if (pBaseCraftedItem->craftedItem)
		{
			ICraftable* craftableItem = GetWorld()->SpawnActor<ICraftable>(pBaseCraftedItem->craftedItem);
			if (craftableItem)
			{
				craftableItem->InitializeCraftable(owner);
			}
		}
	}
}



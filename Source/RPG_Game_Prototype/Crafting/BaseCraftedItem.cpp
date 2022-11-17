	// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCraftedItem.h"

#include "RPG_Game_Prototype/CrafterComponent.h"
#include "BaseCraftedItem.h"
#include "RPG_Game_Prototype/MyPlayer.h"

UBaseCraftedItem::UBaseCraftedItem()
{
}

bool UBaseCraftedItem::CanCraftedItemCraftable()
{
	
	for (FCraftedItemRequirements itemRequirements : requirementList)
	{
		FCraftMaterialProperties craftMateriaProperties = crafterComponent->GetCraftMaterialProperties(itemRequirements.craftMaterialType);
		if (craftMateriaProperties.materialType != ECraftMaterial::None &&
		 craftMateriaProperties.materialQuantity >= itemRequirements.quantity)
			canCraftable = true;
		else
		{
			canCraftable = false;
			return canCraftable;
		}
	}

	return canCraftable;
}

	void UBaseCraftedItem::InitializeCraftedItem()
	{
	
		FString requirementsString = "";
        		 
		for (int i = 0; i < requirementList.Num(); i++)
			requirementsString.Append(FString::FromInt(requirementList[i].quantity) + requirementList[i].materialName + "\n");
	    
		requirementsInText = FText::FromString(requirementsString);
	}

	
	


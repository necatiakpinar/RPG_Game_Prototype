	// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCraftedItem.h"

#include "RPG_Game_Prototype/CrafterComponent.h"
#include "RPG_Game_Prototype/MyPlayer.h"

UBaseCraftedItem::UBaseCraftedItem()
{
	
}

bool UBaseCraftedItem::CanCraftedItemCraftable()
{
	//TODO: Create initialize for each instance!
	player = Cast<AMyPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	crafterComponent = player->crafterComponentImplemented;
	
	for (FCraftedItemRequirements itemRequirements : requirementList)
	{
		FCraftMaterialProperties craftMateriaProperties = crafterComponent->GetCraftMaterialProperties(itemRequirements.craftMaterialType);
		if (craftMateriaProperties.materialType != ECraftMaterial::None &&
		 craftMateriaProperties.materialQuantity >= itemRequirements.quantity)
			canCraftable = true;
		else
			canCraftable = false;
	}

	return canCraftable;
}


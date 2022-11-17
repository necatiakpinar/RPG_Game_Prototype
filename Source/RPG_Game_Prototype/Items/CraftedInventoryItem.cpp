// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftedInventoryItem.h"
#include "RPG_Game_Prototype/Crafting/BaseCraftedItem.h"
#include "InventoryComponent.h"

void UCraftedInventoryItem::Use(AMyPlayer* pCharacter)
{
	if (pCharacter)
		if (owningInventory)
			owningInventory->EquipItem(this);
}
	


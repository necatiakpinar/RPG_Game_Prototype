// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "CraftedInventoryItem.h"
#include "Item.h"
#include "RPG_Game_Prototype/BaseCharacter.h"
#include "RPG_Game_Prototype/Crafting/BaseCraftedItem.h"
#include "RPG_Game_Prototype/Interfaces/Craftable.h"
#include "RPG_Game_Prototype/Interfaces/Equippable.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	capacity = 20;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	owner = Cast<ABaseCharacter>(GetOwner());
	
	for (auto& item : defaultItems)
	{
		AddItem(item);
	}
	UE_LOG(LogTemp, Warning, TEXT("TEST"));
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UInventoryComponent::AddItem(UItem* pItem)
{
	if (items.Num() >= capacity || !pItem)
	{
		return false;
	}

	pItem->owningInventory = this;
	pItem->world = GetWorld();
	items.Add(pItem);
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UItem* pItem)
{
	if (pItem)
	{
		pItem->owningInventory = this;
		pItem->world = GetWorld();
		items.Remove(pItem);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}

void UInventoryComponent::EquipItem(UItem* pItem)
{
	UCraftedInventoryItem* craftedInventoryItem = Cast<UCraftedInventoryItem>(pItem);

	if (craftedInventoryItem)
	{
		IEquippable* equippableItem = GetWorld()->SpawnActor<IEquippable>(craftedInventoryItem->craftedItemBP);
		if (equippableItem)
			equippableItem->Equip(owner);
	}
}


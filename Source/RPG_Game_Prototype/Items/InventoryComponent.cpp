// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Item.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	capacity = 20;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	for (auto& item : defaultItems)
	{
		AddItem(item);
	}
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


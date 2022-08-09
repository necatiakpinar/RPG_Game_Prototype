// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem::UItem()
{
	weight = 1.0f;
	itemDisplayName = FText::FromString("Item");
	useActionText = FText::FromString("Use");
}

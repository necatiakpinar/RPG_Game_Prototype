// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "RPG_GAME_PROTOTYPE/MyPlayer.h"

UItem::UItem()
{
	weight = 1.0f;
	itemDisplayName = FText::FromString("Item");
	useActionText = FText::FromString("Use");
}

void UItem::Use(AMyPlayer* pCharacter)
{
	UE_LOG(LogTemp, Warning, TEXT("LOKKA"));
}

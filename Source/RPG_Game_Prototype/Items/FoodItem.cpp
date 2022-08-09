// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "RPG_Game_Prototype/MyPlayer.h"

void UFoodItem::Use(AMyPlayer* pCharacter)
{
	if (pCharacter)
	{
		pCharacter->health += healthToHeal;
	}
}

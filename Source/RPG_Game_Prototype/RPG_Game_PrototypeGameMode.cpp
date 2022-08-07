// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_Game_PrototypeGameMode.h"
#include "RPG_Game_PrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPG_Game_PrototypeGameMode::ARPG_Game_PrototypeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

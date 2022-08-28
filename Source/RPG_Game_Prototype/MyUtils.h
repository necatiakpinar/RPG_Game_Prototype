// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyUtils.generated.h"


UCLASS()
class RPG_GAME_PROTOTYPE_API UMyUtils : public UObject
{
	GENERATED_BODY()

public:
	static void Test();
	static FString GetEnumValue(uint8 pEnum, FString pEnumName);
};

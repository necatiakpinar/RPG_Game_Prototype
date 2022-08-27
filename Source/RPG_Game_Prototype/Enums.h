// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EObjectiveType : uint8
{
	None UMETA(DisplayName = "None"),
	Kill UMETA(DisplayName = "KILL"),
	Collect UMETA(DisplayName = "COLLECT")
};
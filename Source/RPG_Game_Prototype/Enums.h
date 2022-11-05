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

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	None UMETA(DisplayName = "None"),
	Melee UMETA(DisplayName = "MELEE"),
	Ranged UMETA(DisplayName = "RANGED")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None UMETA(DisplayName = "None"),
	Melee UMETA(DisplayName = "MELEE"),
	Ranged UMETA(DisplayName = "RANGED")
};

UENUM(BlueprintType)
enum class ECraftMaterial : uint8
{
	None UMETA(DisplayName = "None"),
	Stick UMETA(DisplayName = "Stick"),
	Rock UMETA(DisplayName = "Rock"),
	Cloth UMETA(DisplayName = "Cloth"),
	Rope UMETA(DisplayName = "Rope"),
	Count
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EObjectiveType : uint8
{
	None UMETA(DisplayName = "NONE"),
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
	Stick UMETA(DisplayName = "STICK"),
	Rock UMETA(DisplayName = "ROCK"),
	Cloth UMETA(DisplayName = "CLOTH"),
	Rope UMETA(DisplayName = "ROPE"),
	Count
};

UENUM(BlueprintType)
enum class EWeaponAnimationType : uint8
{
	None UMETA(DisplayName = "NONE"),
	HitAxe UMETA(DisplayName = "AXE_HIT"),
	ReloadRifle UMETA(DisplayName = "RELOAD_RIFLE")
};
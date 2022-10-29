// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPG_Game_Prototype/Enums.h"
#include "RPG_Game_Prototype/Interfaces/Collectable.h"
#include "RPG_Game_Prototype/Macros.h"
#include "CraftMaterial.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API ACraftMaterial : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Attributes")
	ECraftMaterial materialType = ECraftMaterial::None;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	UBoxComponent* boxComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* meshComponent;
	
public:	
	ACraftMaterial();
	
	virtual void Initialize() PURE_VIRTUAL(ACraftMaterial,);
	
};

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
class UDACraftMaterialAttributes;

USTRUCT(BlueprintType)
struct FCraftMaterialAttributes
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ECraftMaterial materialType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Multiline = true))
	FText materialDescription;

};


UCLASS(Abstract, Blueprintable, DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API ACraftMaterial : public AActor, public ICollectable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FCraftMaterialAttributes materialAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDACraftMaterialAttributes* daMaterialProperties;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	UBoxComponent* boxComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* meshComponent;

public:	
	ACraftMaterial();
	void Initialize();
	virtual void Collect() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
};

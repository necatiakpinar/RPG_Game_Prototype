// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPG_Game_Prototype/Enums.h"
#include "RPG_Game_Prototype/Interfaces/Collectable.h"
#include "RPG_Game_Prototype/Macros.h"
#include "CraftMaterial.generated.h"

USTRUCT(BlueprintType)
struct FCraftMaterialAttributes
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString materialName;

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
	class UDACraftMaterialAttributes* daMaterialProperties;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	class UBoxComponent* boxComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* meshComponent;

private:
	class AMyPlayer* player;
	class UCrafterComponent* crafterComponent;

public:	
	ACraftMaterial();
	void Initialize();
	virtual void Collect() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
};

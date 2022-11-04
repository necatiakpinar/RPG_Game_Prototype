// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/BaseCraftedItem.h"
#include "DataAssets/DACraftMaterialAttributes.h"
#include "RPG_Game_Prototype/Enums.h"
#include "CrafterComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCrafterMaterialsUpdated);


USTRUCT(BlueprintType)
struct FCraftMaterialProperties
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString materialName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECraftMaterial materialType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 materialQuantity;

	FCraftMaterialProperties()
	{
		materialName = "";
		materialType = ECraftMaterial::None;
		materialQuantity = 0;
	}
	
	FCraftMaterialProperties(FString pMaterialName, ECraftMaterial pMaterialType, int32 pMaterialQuantity)
	{
		materialName = pMaterialName;
		materialType = pMaterialType;
		materialQuantity = pMaterialQuantity;
	}
	
	
};

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),
	DefaultToInstanced)
class RPG_GAME_PROTOTYPE_API UCrafterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCrafterComponent();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TMap<ECraftMaterial, FCraftMaterialProperties> materialDict;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<class UDACraftMaterialAttributes*> materialDataList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBaseCraftedItem* craftedItemBP;
	
	UPROPERTY(BlueprintAssignable, Category = "Crafter")
	FOnCrafterMaterialsUpdated OnCrafterMaterialsUpdated;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Initialize();

	UFUNCTION(BlueprintCallable)
	FCraftMaterialProperties GetCraftMaterialProperties(ECraftMaterial pMaterialType);
	UFUNCTION(BlueprintCallable)
	void IncreaseMaterialQuantity(ECraftMaterial pMaterialType, int32 pIncreaseAmount = 1);
	
	UFUNCTION(BlueprintCallable)
	void DecreaseMaterialQuantity(ECraftMaterial pMaterialType, int32 pDecreaseAmount = 1);

	UFUNCTION(BlueprintCallable)
	void CreateCraftedItem(class UBaseCraftedItem* pBaseCraftedItem);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums.h"
#include "BaseAnimationComponent.generated.h"


USTRUCT(BlueprintType)
struct FAnimMontageWeaponAttack
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	EWeaponAnimationType animationType;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UAnimMontage* animationMontage;
	
};

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_GAME_PROTOTYPE_API UBaseAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseAnimationComponent();

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TMap<EWeaponAnimationType,UAnimMontage*> weaponAnimationDict;
	//TArray<FAnimMontageWeaponAttack> animMontageWeaponAttackList;
	

private:
	class ABaseCharacter* owner;
	class UAnimInstance* animInstance;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	void PlayWeaponAnimation(EWeaponAnimationType pAnimationType);
	bool IsWeaponAnimMontagePlaying(EWeaponAnimationType pAnimationType);
};

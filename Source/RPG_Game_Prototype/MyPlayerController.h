// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
class AMyPlayer;

UCLASS()
class RPG_GAME_PROTOTYPE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	AMyPlayer* player;

private:
	virtual void SetupInputComponent() override;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:

	void Jump();
	void StopJumping();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void AddControllerYawInput(float Rate);
	void AddControllerPitchInput(float Rate);
	void LookUpAtRate(float Rate);
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void InteractPressed();
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThrowableItem.generated.h"

class UStaticMeshComponent;
UCLASS()
class RPG_GAME_PROTOTYPE_API AThrowableItem : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* itemMesh;
	
	FTimerHandle timerHandler;
	int8 lifeTime;
public:	
	// Sets default values for this actor's properties
	AThrowableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LaunchThrowable(FVector pImpulse, FVector pLocation);
	void DestroyObject();
};


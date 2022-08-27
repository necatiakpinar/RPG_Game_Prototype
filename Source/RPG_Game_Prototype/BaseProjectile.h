// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class RPG_GAME_PROTOTYPE_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

public:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* collisionSphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		class UProjectileMovementComponent* projectileMovementComponent;
private:
	float damage;

public:
	void Initialize(float pDamage);
	UFUNCTION()
		void OnHit(UPrimitiveComponent* pHitComp, AActor* pOtherActor,
			UPrimitiveComponent* pOtherComp, int32 pOtherBodyIndex,
			bool bFromSweep, const FHitResult& hit);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"
#include "Damageable.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	collisionSphere->InitSphereRadius(7.0f);

	RootComponent = collisionSphere;
	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovementComponent->UpdatedComponent = collisionSphere;
	projectileMovementComponent->InitialSpeed = 3000.0f;
	projectileMovementComponent->MaxSpeed = 3000.0f;
	projectileMovementComponent->bRotationFollowsVelocity = true;
	projectileMovementComponent->bShouldBounce = true;
}


// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	collisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABaseProjectile::OnHit);
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseProjectile::Initialize(float pDamage)
{
	damage = pDamage;
}

void ABaseProjectile::OnHit(UPrimitiveComponent* pHitComp, AActor* pOtherActor, UPrimitiveComponent* pOtherComp, int32 pOtherBodyIndex, bool bFromSweep, const FHitResult& hit)
{
	if (pOtherActor)
	{
		IDamageable* damageablObject = Cast<IDamageable>(hit.GetActor());
		if (damageablObject)
		{
			damageablObject->TakeDamage(damage);
		}

	}
	//	UE_LOG(LogTemp, Warning, TEXT("%s"),*pOtherActor->GetActorNameOrLabel());
	
}
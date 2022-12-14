// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyPlayer.h"
#include "MyUtils.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Items/Item.h"
#include "Items/InventoryComponent.h"
#include "QuestLogComponent.h"
#include "Quest.h"
#include "CrafterComponent.h"

#include "Interfaces/Collectable.h"

AMyPlayer::AMyPlayer()
{
	InitializeMovement();
	traceDistance = 2000;
	Attributes.health = 1000.f;
	inventoryComponent = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	inventoryComponent->capacity = 20;
}

void AMyPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	questLogComponentImplemented = FindComponentByClass<UQuestLogComponent>();
	crafterComponentImplemented = FindComponentByClass<UCrafterComponent>();

}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	// TArray<UActorComponent*> components;
	// GetComponents(components);
	// for (auto component : components)
	// {
	// 	if (UQuestLogComponent* QuestLogComponent = Cast<UQuestLogComponent>(component))
	// 	{
	// 		questLogComponentImplemented = QuestLogComponent;
	// 	}
	// }
	
	//GetComponentOfActor(*questLogComponentImplemented);
	//UE_LOG(LogTemp, Warning, TEXT("%d"),components.Num());
	//
	// if (questLogComponentImplemented)
	// {
	// 	print(-1,5.0f,UMyUtils::GetEnumValue((uint8)(questLogComponentImplemented->activeQuest->objective.objectiveType),"EObjectiveType"));
	// }
	
		
}


void AMyPlayer::GetComponentOfActor(UQuestLogComponent* pActorComponent)
{
	TArray<UActorComponent*> components;
	GetComponents(components);
	for (auto component : components)
	{
		if (UQuestLogComponent* targetComponent = Cast<UQuestLogComponent>(component))
		{
	//s		print(-1,5.0f,"lokkacinoo");
			pActorComponent = targetComponent;
		}
	}
}



void AMyPlayer::InitializeMovement()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	//GetCharacterMovement()->MaxWalkSpeed = 10.0f
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AMyPlayer::TraceForward_Implementation()
{
	FVector location;
	FRotator rotation;
	FHitResult hit;
	GetController()->GetPlayerViewPoint(location, rotation);

	FVector start = location;
	FVector end = start + (rotation.Vector() * traceDistance);
	FCollisionQueryParams traceParams;

	bool bHit = GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, traceParams);
//	DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 2.0f);

	crossHairLocation = hit.TraceEnd;

	if (bHit)
	{
		crossHairLocation = hit.ImpactPoint;
		if (hit.GetActor())
		{
			IInteractable* interactableObject = Cast<IInteractable>(hit.GetActor());
			ICollectable* collectableObject = Cast<ICollectable>(hit.GetActor());
			
			if (interactableObject)
				interactableObject->Interact();
			
			if (collectableObject)
				collectableObject->Collect();
		}
	}
	//hit.TraceEnd

}

void AMyPlayer::UseItem(UItem* pItem)
{
	if (pItem)
	{
		pItem->Use(this);
		pItem->OnUse(this); //BP Event
	}
}

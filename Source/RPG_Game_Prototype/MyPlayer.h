// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.h"
#include "MyPlayer.generated.h"


UCLASS(config=Game)
class RPG_GAME_PROTOTYPE_API AMyPlayer : public ABaseCharacter
{
	GENERATED_BODY()
public:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components , meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* inventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components , meta = (AllowPrivateAccess = "true"))
	class UQuestLogComponent* questLogComponentImplemented;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components , meta = (AllowPrivateAccess = "true"))
	class UCrafterComponent* crafterComponentImplemented;

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool turnRight;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool turnLeft;

public:
	AMyPlayer();
	void InitializeMovement();
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, Category = "Items") 
	void UseItem(class UItem* pItem);
	void GetComponentOfActor(UQuestLogComponent* pActorComponent);

	virtual void TraceForward_Implementation() override;
	
protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
};


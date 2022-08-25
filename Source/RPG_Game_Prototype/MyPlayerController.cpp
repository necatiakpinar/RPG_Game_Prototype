// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AMyPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (player)
		Possess(player);	
	else
	UE_LOG(LogTemp, Error, TEXT("Your player is NULL !"));

//	bShowMouseCursor = true;
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyPlayerController::StopJumping);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMyPlayerController::InteractPressed);
	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMyPlayerController::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AMyPlayerController::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &AMyPlayerController::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AMyPlayerController::LookUpAtRate);
	InputComponent->BindTouch(IE_Pressed, this, &AMyPlayerController::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AMyPlayerController::TouchStopped);


}

void AMyPlayerController::Jump()
{
	player->Jump();
}
void AMyPlayerController::StopJumping()
{
	player->StopJumping();
}

void AMyPlayerController::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	player->Jump();
}

void AMyPlayerController::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	player->StopJumping();
}

void AMyPlayerController::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	player-> AddControllerYawInput(Rate * player->BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayerController::AddControllerYawInput(float Rate)
{
	player->AddControllerYawInput(Rate);
	
	if (player->GetVelocity().Length() == 0)
	{
		if (Rate > 0.3f)
		{
			player->turnRight = true;
			player->turnLeft = false;
		}
		else
		{
			player->turnRight = false;
		}

		if (Rate < -0.3f)
		{
			player->turnLeft = true;
			player->turnRight = false;
		}
		else
		{
			player->turnLeft = false;
		}

	}
	else
	{
		player->turnRight = false;
		player->turnLeft = false;
	}



}

void AMyPlayerController::AddControllerPitchInput(float Rate)
{
	player->AddControllerPitchInput(Rate);
}

void AMyPlayerController::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	player->AddControllerPitchInput(Rate * player->BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMyPlayerController::MoveForward(float Value)
{
	if ((this != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		player->AddMovementInput(Direction, Value);
	}
}

void AMyPlayerController::MoveRight(float Value)
{
	if ((this != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		player->AddMovementInput(Direction, Value);
	}
}


void AMyPlayerController::InteractPressed()
{
	player->TraceForward_Implementation();
}
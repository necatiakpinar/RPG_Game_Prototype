// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "MyPlayer.h"
#include "Quest.h"
#include "Macros.h"
#include "Enums.h"

AEnemy::AEnemy()
{
	
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	// CastQuestComponent();
	// GetWorld()->GetTimerManager().SetTimer(timerHandler, this, &AEnemy::CastQuestComponent, 1.0f, true, 0.0f);
}

void AEnemy::AddToTheQuestComponent()
{
	 player = Cast<AMyPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player)
	{
		if (player->questLogComponentImplemented)
		{
			player->questLogComponentImplemented->UpdateQuests(-1,this);
		}
//		GetWorld()->GetTimerManager().ClearTimer(timerHandler);
	}
}

void AEnemy::Die()
{
	Super::Die();
	AddToTheQuestComponent();
}

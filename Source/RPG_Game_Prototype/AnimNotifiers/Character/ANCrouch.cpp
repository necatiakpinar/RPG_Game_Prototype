// Fill out your copyright notice in the Description page of Project Settings.


#include "ANCrouch.h"

void UANCrouch::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	UE_LOG(LogTemp, Warning,TEXT("TESTTT"));
}

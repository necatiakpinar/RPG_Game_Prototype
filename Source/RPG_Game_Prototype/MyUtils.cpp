// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUtils.h"
#include "Enums.h"


FString UMyUtils::GetEnumValue(uint8 pEnum, FString pEnumName)
{
	UE_LOG(LogTemp, Warning, TEXT("Enum value => %d"),pEnum);
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *pEnumName, true);
	FString enumValue;
	if (EnumPtr)
		enumValue = EnumPtr->GetDisplayNameTextByValue((pEnum)).ToString();
	
	return enumValue;
}

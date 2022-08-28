// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUtils.h"
#include "Enums.h"

void UMyUtils::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("Static func"));
}

FString UMyUtils::GetEnumValue(uint8 pEnum, FString pEnumName)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EObjestiveType"), true);
	FString enumValue;
	if (EnumPtr)
		enumValue = EnumPtr->GetDisplayNameTextByValue((pEnum)).ToString();

	return enumValue;
}

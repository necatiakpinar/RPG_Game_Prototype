// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define print(Key, Time, Message) if (GEngine) GEngine->AddOnScreenDebugMessage(Key, Time, FColor::Red, Message)



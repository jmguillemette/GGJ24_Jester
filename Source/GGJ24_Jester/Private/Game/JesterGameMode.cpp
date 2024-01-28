// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/JesterGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Game/JesterGameState.h"

void AJesterGameMode::BeginPlay()
{
	Super::BeginPlay();
	AJesterGameState* State = GetGameState<AJesterGameState>();
	State->bIsPlaying = false;
	State->Score = 0;
}





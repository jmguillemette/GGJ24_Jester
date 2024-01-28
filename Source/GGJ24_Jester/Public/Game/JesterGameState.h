// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "JesterGameState.generated.h"

/**
 * 
 */
UCLASS()
class GGJ24_JESTER_API AJesterGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	int Score = 0;
	bool bIsPlaying = false;
	float GamePlayTime = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "JesterGameInstanceSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartOfRoundDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndOfRoundDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdateDelegate,float,ScoreUpdate);

UCLASS()
class GGJ24_JESTER_API UJesterGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintCallable)
	FOnStartOfRoundDelegate OnStartOfRoundDelegate;

	UPROPERTY(BlueprintCallable)
	FOnEndOfRoundDelegate OnEndOfRoundDelegate;

	UPROPERTY(BlueprintCallable)
	FOnScoreUpdateDelegate OnScoreUpdate;

	void StartRound();
	void EndRound();
	void ScoreUpdate(float Value);
	
};

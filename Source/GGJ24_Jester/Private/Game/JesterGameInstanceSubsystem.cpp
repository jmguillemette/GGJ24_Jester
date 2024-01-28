// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/JesterGameInstanceSubsystem.h"

void UJesterGameInstanceSubsystem::StartRound()
{
	if(OnStartOfRoundDelegate.IsBound())
	{
		OnStartOfRoundDelegate.Broadcast();
	}
}

void UJesterGameInstanceSubsystem::EndRound()
{
	if(OnEndOfRoundDelegate.IsBound())
	{
		OnEndOfRoundDelegate.Broadcast();
	}
}

void UJesterGameInstanceSubsystem::ScoreUpdate(float Value)
{
	if(OnScoreUpdate.IsBound())
	{
		OnScoreUpdate.Broadcast(Value);
	}
}

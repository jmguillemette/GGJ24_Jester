// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ScoreWidget.h"

#include "Components/TextBlock.h"
#include "Game/JesterGameInstanceSubsystem.h"

bool UScoreWidget::Initialize()
{
	return Super::Initialize();
	
}

void UScoreWidget::Setup()
{
	UJesterGameInstanceSubsystem* JesterGameInstanceSubsystem = GetGameInstance()->GetSubsystem<UJesterGameInstanceSubsystem>();
	JesterGameInstanceSubsystem->OnScoreUpdate.AddDynamic(this,&UScoreWidget::OnScoreUpdate);

	FString Message = FString::Printf(TEXT("Score: %f"),0.f);
	ScoreText->SetText(FText::FromString(Message));
}

void UScoreWidget::OnScoreUpdate(float Value)
{
	UE_LOG(LogTemp,Log, TEXT("Score = %f"),Value);
	FString Message = FString::Printf(TEXT("Score: %f"),Value);
	ScoreText->SetText(FText::FromString(Message));
}

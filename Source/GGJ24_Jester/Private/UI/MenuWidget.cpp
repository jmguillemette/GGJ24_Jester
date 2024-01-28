// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MenuWidget.h"

#include "Components/Button.h"
#include "Game/JesterGameInstanceSubsystem.h"
#include "Game/JesterGameMode.h"
#include "Game/JesterGameState.h"

bool UMenuWidget::Initialize()
{
	bool Result =  Super::Initialize();
	if(!Result)
	{
		return Result;
	}
	PlayButton->OnClicked.AddDynamic(this,&UMenuWidget::OnPlay);
	QuitButton->OnClicked.AddDynamic(this,&UMenuWidget::OnQuit);
	
	return Result;
}

void UMenuWidget::SetupMenu()
{
	JesterGameInstanceSubsystem = GetGameInstance()->GetSubsystem<UJesterGameInstanceSubsystem>();
	JesterGameInstanceSubsystem->OnEndOfRoundDelegate.AddDynamic(this,&UMenuWidget::ShowMenu);
}

void UMenuWidget::ShowMenu()
{
	AddToViewport(0);
}

void UMenuWidget::OnPlay()
{
	GEngine->AddOnScreenDebugMessage(0,3,FColor::Cyan,TEXT("OnPlay"));
	GetWorld()->GetGameState<AJesterGameState>()->Score =0;
	GetWorld()->GetGameState<AJesterGameState>()->bIsPlaying = true;
	JesterGameInstanceSubsystem->StartRound();
	RemoveFromParent();	
}

void UMenuWidget::OnQuit()
{
	GEngine->AddOnScreenDebugMessage(0,3,FColor::Cyan,TEXT("OnQuit"));
	FGenericPlatformMisc::RequestExit(false);
}

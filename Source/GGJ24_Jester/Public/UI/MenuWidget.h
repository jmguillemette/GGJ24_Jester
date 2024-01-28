// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

class UJesterGameInstanceSubsystem;
class UButton;
/**
 * 
 */
UCLASS()
class GGJ24_JESTER_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	TObjectPtr<UJesterGameInstanceSubsystem> JesterGameInstanceSubsystem; 

	virtual bool Initialize() override;
	
	UPROPERTY(meta=(BindWidget))
	UButton* PlayButton;

	UPROPERTY(meta=(BindWidget))
	UButton* QuitButton;

	UFUNCTION(BlueprintCallable)
	void SetupMenu();
	
	UFUNCTION(BlueprintCallable)
	void ShowMenu();
	
	UFUNCTION(BlueprintCallable)
	void OnPlay();
	UFUNCTION(BlueprintCallable)
	void OnQuit();

	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class GGJ24_JESTER_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
public:


	UPROPERTY(meta=(BindWidget))
	UTextBlock* ScoreText;
	
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void Setup();
	
	UFUNCTION()
	void OnScoreUpdate(float Value);
};

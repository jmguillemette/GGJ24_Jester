// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JesterPlayerController.generated.h"

class UJesterGameInstanceSubsystem;
class AJesterGameState;
class UInputAction;
struct FInputActionInstance;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class GGJ24_JESTER_API AJesterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	TObjectPtr<UJesterGameInstanceSubsystem> JesterGameInstanceSubsystem;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> InputMappingContext;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> MoveAction;
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	TObjectPtr<AJesterGameState> JesterGameState;


	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
	void OnStartOfRound();
	UFUNCTION()
	void OnEndOfRound();
protected:
	virtual void OnMove(const FInputActionInstance& Instance);
	
private:
	
	TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent;
	float Score = 0;
	
};

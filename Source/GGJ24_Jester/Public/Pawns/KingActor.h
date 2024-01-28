// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KingActor.generated.h"

class UJesterGameInstanceSubsystem;

UCLASS()
class GGJ24_JESTER_API AKingActor : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAudioComponent> LaughAudioComponent;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAudioComponent> MusicAudioComponent;
	TObjectPtr<UJesterGameInstanceSubsystem> JesterGameInstanceSubsystem;
	
	AKingActor();
	virtual void Tick(float DeltaTime) override;


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnBeginRound();
	UFUNCTION()
	virtual void OnEndRound();
	
};

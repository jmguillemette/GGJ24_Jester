// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PeasantPawn.generated.h"

class AJesterGameState;

UCLASS()
class GGJ24_JESTER_API APeasantPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Peasant")
	TSubclassOf<class APeasantProjectile> Projectile;
	UPROPERTY(EditAnywhere, Category="Peasant")
	float MinWaitTime = 5.f;
	UPROPERTY(EditAnywhere, Category="Peasant")
	float MaxWaitTime = 10.f;
	UPROPERTY(EditAnywhere, Category="Peasant")
	bool bIsThrower = true;
	
	// Sets default values for this pawn's properties
	APeasantPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAudioComponent> TossSoundComponent;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual  void FireProjectile();
	virtual void CreateNewTargetWaitTime();
	
private:
	float CurrentWaitTime = 0;
	float TargetWaitTime = 5.f;
	TObjectPtr<AJesterGameState> JesterGameState;
};

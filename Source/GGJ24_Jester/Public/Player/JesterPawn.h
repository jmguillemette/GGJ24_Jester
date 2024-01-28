// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "JesterPawn.generated.h"

class UJesterGameInstanceSubsystem;
class USphereComponent;

UCLASS()
class GGJ24_JESTER_API AJesterPawn : public ACharacter
{
	GENERATED_BODY()

public:

	TObjectPtr<UJesterGameInstanceSubsystem> JesterGameInstanceSubsystem;
	TObjectPtr<USphereComponent> CollisionComponent;
	
	AJesterPawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
};

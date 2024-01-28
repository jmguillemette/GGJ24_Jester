// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PeasantProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class GGJ24_JESTER_API APeasantProjectile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float MaxLifetimeSeconds = 5;
	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAudioComponent> SplatAudioComponent;
	
	// Sets default values for this actor's properties
	APeasantProjectile();
	virtual void Tick(float DeltaTime) override;
	virtual void FireInDirection(FVector Direction);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	virtual void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
private:
	float TargetLifetimeInSeconds = 3.0f;
	float CurrentLifetimeSeconds = 0;
	

};

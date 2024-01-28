// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/JesterPawn.h"

#include "Components/SphereComponent.h"
#include "Game/JesterGameInstanceSubsystem.h"
#include "Game/JesterGameMode.h"
#include "Game/JesterGameState.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "UI/MenuWidget.h"


// Sets default values
AJesterPawn::AJesterPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AJesterPawn::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this,&AJesterPawn::OnHit);
	JesterGameInstanceSubsystem = GetGameInstance()->GetSubsystem<UJesterGameInstanceSubsystem>();
}


void AJesterPawn::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//GEngine->AddOnScreenDebugMessage(0,3,FColor::Yellow,TEXT("HIT"));
}

void AJesterPawn::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(0,3,FColor::Yellow,TEXT("HIT"));
	GetWorld()->GetGameState<AJesterGameState>()->bIsPlaying = false;
	JesterGameInstanceSubsystem->EndRound();
	
}


// Called every frame
void AJesterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AJesterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


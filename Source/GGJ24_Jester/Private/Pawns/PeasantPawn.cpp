// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/PeasantPawn.h"
#include "Components/AudioComponent.h"
#include "Game/JesterGameState.h"
#include "Projectiles/PeasantProjectile.h"


// Sets default values
APeasantPawn::APeasantPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = bIsThrower;
	TossSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Toss Sound Component"));
	TossSoundComponent->bAutoActivate= false;
	TossSoundComponent->SetupAttachment(GetRootComponent());
	
}

// Called when the game starts or when spawned
void APeasantPawn::BeginPlay()
{
	Super::BeginPlay();
	CreateNewTargetWaitTime();
	JesterGameState = GetWorld()->GetGameState<AJesterGameState>();
}

// Called every frame
void APeasantPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bIsThrower && JesterGameState->bIsPlaying)
	{
		
		CurrentWaitTime += DeltaTime;
		if(CurrentWaitTime >= TargetWaitTime)
		{
			CurrentWaitTime = 0;
			CreateNewTargetWaitTime();
			FireProjectile();
		}
	}
}

// Called to bind functionality to input
void APeasantPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APeasantPawn::FireProjectile()
{
	
	TossSoundComponent->SetRelativeLocation(GetActorLocation());
	TossSoundComponent->Play();
	
	APeasantProjectile* PeasantProjectile = GetWorld()->SpawnActor<APeasantProjectile>(Projectile.GetDefaultObject()->GetClass(),GetActorLocation(), GetActorRotation());
	PeasantProjectile->FireInDirection(GetActorRotation().Vector());
	
}

void APeasantPawn::CreateNewTargetWaitTime()
{
	TargetWaitTime = FMath::RandRange(MinWaitTime, MaxWaitTime);
}
	


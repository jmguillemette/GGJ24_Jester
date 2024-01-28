// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/KingActor.h"
#include "Components/AudioComponent.h"
#include "Game/JesterGameInstanceSubsystem.h"


// Sets default values
AKingActor::AKingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LaughAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Laugh Audio"));
	MusicAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Music Audio"));
	SetRootComponent(LaughAudioComponent);
	MusicAudioComponent->SetupAttachment(GetRootComponent());
	
}

// Called when the game starts or when spawned
void AKingActor::BeginPlay()
{
	Super::BeginPlay();
	JesterGameInstanceSubsystem = GetGameInstance()->GetSubsystem<UJesterGameInstanceSubsystem>();
	JesterGameInstanceSubsystem->OnStartOfRoundDelegate.AddDynamic(this,&AKingActor::OnBeginRound);
	JesterGameInstanceSubsystem->OnEndOfRoundDelegate.AddDynamic(this,&AKingActor::OnEndRound);
	
}

void AKingActor::OnBeginRound()
{
	MusicAudioComponent->Play();
}

void AKingActor::OnEndRound()
{
	MusicAudioComponent->Stop();
	LaughAudioComponent->Play();
}

// Called every frame
void AKingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "GGJ24_Jester/Public/Player/JesterPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Game/JesterGameInstanceSubsystem.h"
#include "Game/JesterGameState.h"


void AJesterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	JesterGameInstanceSubsystem = GetGameInstance()->GetSubsystem<UJesterGameInstanceSubsystem>();
	JesterGameInstanceSubsystem->OnStartOfRoundDelegate.AddDynamic(this,&AJesterPlayerController::OnStartOfRound);
	JesterGameInstanceSubsystem->OnEndOfRoundDelegate.AddDynamic(this,&AJesterPlayerController::OnEndOfRound);
	if(InputMappingContext)
	{
		GEngine->AddOnScreenDebugMessage(0,3,FColor::Green,FString("Registering Enhanced Input"));
		UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		EnhancedInputLocalPlayerSubsystem->AddMappingContext(InputMappingContext,0);
	}
	JesterGameState = GetWorld()->GetGameState<AJesterGameState>();
}

void AJesterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if(!EnhancedInputComponent)
	{
		GEngine->AddOnScreenDebugMessage(0,3,FColor::Red,FString("Enhanced Input NOT FOUND"));
		return;
	}
	GEngine->AddOnScreenDebugMessage(0,3,FColor::Green,FString("Registering Input Actions"));
	if(MoveAction)
	{
		GEngine->AddOnScreenDebugMessage(0,3,FColor::Green,FString("Registering Input Action: Move"));
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &AJesterPlayerController::OnMove);	
	}
	
	
		
}

void AJesterPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Score += DeltaSeconds;
	JesterGameInstanceSubsystem->ScoreUpdate(Score);
}

void AJesterPlayerController::OnStartOfRound()
{
	GEngine->AddOnScreenDebugMessage(0,3,FColor::Green,TEXT("Start of Round"));
	SetShowMouseCursor(false);
	Score = 0;
	AActor* Possessed = GetPawn();
	FVector Location = FVector(0,0,0);
	Possessed->SetActorLocation(Location);
	
}

void AJesterPlayerController::OnEndOfRound()
{
	SetShowMouseCursor(true);
	
}

void AJesterPlayerController::OnMove(const FInputActionInstance& Instance)
{
	if(JesterGameState->bIsPlaying)
	{
		FInputActionValue InputValue = Instance.GetValue();
		FVector2D Input = InputValue.Get<FVector2D>();
		APawn* Possessed = GetPawn();
		FVector Location = Possessed->GetActorLocation();
		Location.X = Location.X + (Input.X * 100);
		Location.Y = Location.Y + (Input.Y * 100);
		GEngine->AddOnScreenDebugMessage(0,3,FColor::Green,FString::Printf(TEXT("Move [%f,%f,%f]"), Location.X, Location.Y, Location.Z));
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this,Location);
	}
}

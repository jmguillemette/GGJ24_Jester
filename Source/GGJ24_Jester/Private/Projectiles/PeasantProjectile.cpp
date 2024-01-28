// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/PeasantProjectile.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
APeasantProjectile::APeasantProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovementComponent->MaxSpeed=500.f;
	ProjectileMovementComponent->InitialSpeed=500.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->bSweepCollision = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	SetRootComponent(SphereComponent);
	//SphereComponent->SetupAttachment(GetRootComponent());
	OnActorHit.AddDynamic(this,&APeasantProjectile::OnHit);
	SplatAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Splat Audio"));
	SplatAudioComponent->SetupAttachment(SphereComponent);
}

// Called when the game starts or when spawned
void APeasantProjectile::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentHit.AddDynamic(this,&APeasantProjectile::OnComponentHit);
}

void APeasantProjectile::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(1,3,FColor::Red,TEXT("HIT"));
	UE_LOG(LogTemp,Log, TEXT("OnHit"));
}

void APeasantProjectile::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(1,3,FColor::Red,TEXT("HIT"));
	UE_LOG(LogTemp,Log, TEXT("OnComponentHit"));
	SplatAudioComponent->SetWorldLocation(GetActorLocation());
	SplatAudioComponent->Play();
	Destroy();
}




void APeasantProjectile::FireInDirection(FVector Direction)
{
	FVector Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
	ProjectileMovementComponent->Velocity = Velocity;
}


// Called every frame
void APeasantProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentLifetimeSeconds += DeltaTime;
	if(CurrentLifetimeSeconds>=MaxLifetimeSeconds)
	{
		GetWorld()->DestroyActor(this);
	}
}


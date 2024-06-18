// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"

// Sets default values
ACapsula::ACapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mallaCapsula = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaCapsula"));
	mallaCapsula->SetupAttachment(RootComponent);
	RootComponent = mallaCapsula;
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
}

// Called when the game starts or when spawned
void ACapsula::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACapsula::DestruirCapsula, 10.0f, false);
	
}

// Called every frame
void ACapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACapsula::DestruirCapsula()
{
	Destroy();
}


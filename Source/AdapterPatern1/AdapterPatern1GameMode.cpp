// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdapterPatern1GameMode.h"
#include "AdapterPatern1Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "BallAdapter.h"


AAdapterPatern1GameMode::AAdapterPatern1GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAdapterPatern1Pawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
}

void AAdapterPatern1GameMode::BeginPlay()
{
	Super::BeginPlay();
	Jugador = GetWorld()->SpawnActor<AAdapterPatern1Pawn>(AAdapterPatern1Pawn::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);
	Jugador = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Adapter = GetWorld()->SpawnActor<ABallAdapter>(ABallAdapter::StaticClass(),FVector(0,0,0),FRotator::ZeroRotator);
	Jugador->SetBounceBall(Adapter);
    Jugador->Lanzar();
}

void AAdapterPatern1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


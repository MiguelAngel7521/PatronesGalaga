// Fill out your copyright notice in the Description page of Project Settings.


#include "Basico.h"
#include "AdapterPatern1Pawn.h"

// Sets default values
ABasico::ABasico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABasico::EstablecerJugador(AAdapterPatern1Pawn* _Jugador)
{
	Jugador = _Jugador;
}

void ABasico::Basico()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, FString::Printf(TEXT("La vida del jugador decremento un 25%%")));
}


FString ABasico::ObtenerEstado()
{
	return "Nave jugador En estado Basico";
}


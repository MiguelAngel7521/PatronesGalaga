// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoConCamuflaje.h"
#include "AdapterPatern1Pawn.h"

// Sets default values
AEstadoConCamuflaje::AEstadoConCamuflaje()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoConCamuflaje::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoConCamuflaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoConCamuflaje::EstablecerJugador(AAdapterPatern1Pawn* _Jugador)
{
		Jugador = _Jugador;
}

void AEstadoConCamuflaje::ConCamuflaje()
{
	if (Jugador)
	{
		Jugador->JugadorConCamuflaje();
	}
}

FString AEstadoConCamuflaje::ObtenerEstado()
{
	return "Estado Con Camuflaje";
}


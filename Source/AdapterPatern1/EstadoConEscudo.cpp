// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoConEscudo.h"
#include "AdapterPatern1Pawn.h"

// Sets default values
AEstadoConEscudo::AEstadoConEscudo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoConEscudo::BeginPlay()
{
	Super::BeginPlay();
	
}
 
// Called every frame

void AEstadoConEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoConEscudo::EstablecerJugador(AAdapterPatern1Pawn* _Jugador)
{
	Jugador = _Jugador;
}

void AEstadoConEscudo::ConEscudos()
{
	if (Jugador)
	{
		Jugador->JugadorConEscudos();
	}
}

FString AEstadoConEscudo::ObtenerEstado()
{
	return "Jugador En estado con Escudos";
}


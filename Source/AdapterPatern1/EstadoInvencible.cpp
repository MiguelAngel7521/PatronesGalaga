// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoInvencible.h"
#include "AdapterPatern1Pawn.h"

// Sets default values
AEstadoInvencible::AEstadoInvencible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoInvencible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoInvencible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoInvencible::EstablecerJugador(AAdapterPatern1Pawn* _Jugador)
{
	Jugador = _Jugador;
}

void AEstadoInvencible::Invencible()
{
	Jugador->JugadorInvensible();
}

FString AEstadoInvencible::ObtenerEstado()
{
	return FString();
}


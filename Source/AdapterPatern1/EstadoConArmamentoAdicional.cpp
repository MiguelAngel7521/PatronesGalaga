// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoConArmamentoAdicional.h"
#include "AdapterPatern1Pawn.h"

// Sets default values
AEstadoConArmamentoAdicional::AEstadoConArmamentoAdicional()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoConArmamentoAdicional::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoConArmamentoAdicional::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoConArmamentoAdicional::EstablecerJugador(AAdapterPatern1Pawn* _Jugador)
{
	Jugador = _Jugador;
}

void AEstadoConArmamentoAdicional::ConArmamentoAdicional()
{
	if (Jugador)
	{
		Jugador->JugadorConArmasAdicionales();
	}
}

FString AEstadoConArmamentoAdicional::ObtenerEstado()
{
	return "Estas En el Estado Con Armamento Adicional";
}


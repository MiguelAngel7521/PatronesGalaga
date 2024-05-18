// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulasFacade.h"
#include "Nivel.h"
#include "CapsulasTipoFacade.h"

// Sets default values
ACapsulasFacade::ACapsulasFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Nivel = TArray<ACapsulasTipoFacade*>();
	OrdenCapsulas = TArray<FString>();

}

// Called when the game starts or when spawned
void ACapsulasFacade::BeginPlay()
{
	Super::BeginPlay();

	//Creamos el nivel
	NivelActual = GetWorld()->SpawnActor<ANivel>(ANivel::StaticClass());
	Nivel.Add(NivelActual);
}

// Called every frame
void ACapsulasFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACapsulasFacade::NivelesCapsulas(TArray<class ACapsulasTipoFacade*> _Nivel, TArray<FString> _Orden)
{
	for (ACapsulasTipoFacade* TipoCapsulasNivel : _Nivel)
	{
		TipoCapsulasNivel->RecibirOrden(_Orden);
	}
}

void ACapsulasFacade::NivelFacil()
{
	OrdenCapsulas.Empty();
	OrdenCapsulas.Add("Vida");
	OrdenCapsulas.Add("Energia");
	OrdenCapsulas.Add("Velocidad");
	NivelesCapsulas(Nivel, OrdenCapsulas);
}

void ACapsulasFacade::NivelMedio()
{
	OrdenCapsulas.Empty();
	OrdenCapsulas.Add("Vida");
	NivelesCapsulas(Nivel, OrdenCapsulas);
}

void ACapsulasFacade::NivelDificil()
{
	OrdenCapsulas.Empty();
	OrdenCapsulas.Add("SinCapsulas");
	NivelesCapsulas(Nivel, OrdenCapsulas);
}


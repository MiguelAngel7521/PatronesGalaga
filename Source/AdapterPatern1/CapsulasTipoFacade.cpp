// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulasTipoFacade.h"
#include "CapsulaEnergia.h"
#include "CapsulaVida.h"
#include "CapsulaVelocidad.h"

// Sets default values
ACapsulasTipoFacade::ACapsulasTipoFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACapsulasTipoFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACapsulasTipoFacade::CrearCapsulaDeVida()
{
	FVector PosicionCapsulaVida = FVector(500.0f, 0.0f, 250.0f);
	FRotator RotacionCapsulaVida = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeVida = GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass());
	CapsulaDeVida->SetActorLocation(PosicionCapsulaVida);
	CapsulaDeVida->SetActorRotation(RotacionCapsulaVida);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Creando capsula de vida")));
}

void ACapsulasTipoFacade::CrearCapsulaDeEnergia()
{
	FVector PosicionCapsulaEnergia = FVector(700.0f, 0.0f, 250.0f);
	FRotator RotacionCapsulaEnergia = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeEnergia = GetWorld()->SpawnActor<ACapsulaEnergia>(ACapsulaEnergia::StaticClass());
	CapsulaDeEnergia->SetActorLocation(PosicionCapsulaEnergia);
	CapsulaDeEnergia->SetActorRotation(RotacionCapsulaEnergia);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Creando capsula de Energia")));
}

void ACapsulasTipoFacade::CrearCapsulaDeVelocidad()
{
	FVector PosicionCapsulaVelocidad = FVector(900.0f, 0.0f, 250.0f);
	FRotator RotacionCapsulaVelocidad = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeVelocidad = GetWorld()->SpawnActor<ACapsulaVelocidad>(ACapsulaVelocidad::StaticClass());
	CapsulaDeVelocidad->SetActorLocation(PosicionCapsulaVelocidad);
	CapsulaDeVelocidad->SetActorRotation(RotacionCapsulaVelocidad);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Creando capsula de velocidad")));
}

void ACapsulasTipoFacade::BloquearCapsula()
{
}

void ACapsulasTipoFacade::RecibirOrden(const TArray<FString>& _Orden)
{
	for (const FString& Orden : _Orden)
	{
		CrearOrden(Orden);
	}
}

void ACapsulasTipoFacade::CrearOrden(const FString& _Orden)
{
	if (_Orden.Equals("Vida"))
	{
		CrearCapsulaDeVida();
	}
	else if (_Orden.Equals("Energia"))
	{
		CrearCapsulaDeEnergia();
		CrearCapsulaDeEnergia();
	}
	else if (_Orden.Equals("Velocidad"))
	{
		CrearCapsulaDeVelocidad();
	}
	else if (_Orden.Equals("SinCapsulas"))
	{
		BloquearCapsula();
	}
}

// Called every frame
void ACapsulasTipoFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


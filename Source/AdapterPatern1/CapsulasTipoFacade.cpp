// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulasTipoFacade.h"
#include "CapsulaEnergia.h"
#include "CapsulaVida.h"
#include "CapsulaVelocidad.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "IngenieroEspecialista1.h"
#include "IngenieroEspecialista2.h"
#include "IngenieroEspecialista3.h" 
#include "DirectorBuilder.h"
#include "ConstruirNaveEnemiga.h"
 
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
	FVector PosicionCapsulaVida = FVector(-990.0f, -160.0f, 250.0f);
	FRotator RotacionCapsulaVida = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeVida = GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass());
	CapsulaDeVida->SetActorLocation(PosicionCapsulaVida);
	CapsulaDeVida->SetActorRotation(RotacionCapsulaVida);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Creando capsula de vida")));
}

void ACapsulasTipoFacade::CrearCapsulaDeEnergia()
{
	FVector PosicionCapsulaEnergia = FVector(-990.0f, -260.0f, 250.0f);
	FRotator RotacionCapsulaEnergia = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeEnergia = GetWorld()->SpawnActor<ACapsulaEnergia>(ACapsulaEnergia::StaticClass());
	CapsulaDeEnergia->SetActorLocation(PosicionCapsulaEnergia);
	CapsulaDeEnergia->SetActorRotation(RotacionCapsulaEnergia);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Creando capsula de Energia")));
}

void ACapsulasTipoFacade::CrearCapsulaDeVelocidad()
{
	FVector PosicionCapsulaVelocidad = FVector(-990.0f, -360.0f, 250.0f);
	FRotator RotacionCapsulaVelocidad = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeVelocidad = GetWorld()->SpawnActor<ACapsulaVelocidad>(ACapsulaVelocidad::StaticClass());
	CapsulaDeVelocidad->SetActorLocation(PosicionCapsulaVelocidad);
	CapsulaDeVelocidad->SetActorRotation(RotacionCapsulaVelocidad);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Creando capsula de velocidad")));
}

void ACapsulasTipoFacade::BloquearCapsula()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Sin Capsulas")));
}

void ACapsulasTipoFacade::CrearEscuadronEnemigos1()
{

	FVector ubicacionInicioNavesEnemigasCaza = FVector(0.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasCaza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasTransporte = FVector(300.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasTransporte = FRotator(0.0f, 180.0f, 0.0f);


	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 5; i++)
		{
			ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicioNavesEnemigasCaza, rotacionInicioNavesEnemigasCaza);

		}

		for (int i = 0; i < 5; i++)
		{
			ubicacionInicioNavesEnemigasTransporte = ubicacionInicioNavesEnemigasTransporte + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaTransporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionInicioNavesEnemigasTransporte, rotacionInicioNavesEnemigasTransporte);

		}

	}
	
}

void ACapsulasTipoFacade::CrearEscuadronEnemigos2()
{
	FVector ubicacionInicioNavesEnemigasCaza = FVector(0.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasCaza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasTransporte = FVector(300.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasTransporte = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(600.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasEspia = FRotator(0.0f, 180.0f, 0.0f);


	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 8; i++)
		{
			ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicioNavesEnemigasCaza, rotacionInicioNavesEnemigasCaza);

		}

		for (int i = 0; i < 8; i++)
		{
			ubicacionInicioNavesEnemigasTransporte = ubicacionInicioNavesEnemigasTransporte + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaTransporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionInicioNavesEnemigasTransporte, rotacionInicioNavesEnemigasTransporte);

		}
		for (int i = 0; i < 8; i++)
		{
			ubicacionInicioNavesEnemigasEspia = ubicacionInicioNavesEnemigasEspia + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaEspia* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaEspia>(ubicacionInicioNavesEnemigasEspia, rotacionInicioNavesEnemigasEspia);
		}

	}

}

void ACapsulasTipoFacade::CrearEscuadronEnemigos3()
{
	FVector ubicacionInicioNavesEnemigasCaza = FVector(0.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasCaza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasTransporte = FVector(-300.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasTransporte = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(-600.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasEspia = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasNodriza = FVector(-900.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasNodriza = FRotator(0.0f, 180.0f, 0.0f);


	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 5; i++)
		{
			ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicioNavesEnemigasCaza, rotacionInicioNavesEnemigasCaza);

		}

		for (int i = 0; i < 5; i++)
		{
			ubicacionInicioNavesEnemigasTransporte = ubicacionInicioNavesEnemigasTransporte + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaTransporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionInicioNavesEnemigasTransporte, rotacionInicioNavesEnemigasTransporte);

		}
		for (int i = 0; i < 5; i++)
		{
			ubicacionInicioNavesEnemigasEspia = ubicacionInicioNavesEnemigasEspia + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaEspia* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaEspia>(ubicacionInicioNavesEnemigasEspia, rotacionInicioNavesEnemigasEspia);
		}
		for (int i = 0; i < 5; i++)
		{
			ubicacionInicioNavesEnemigasNodriza = ubicacionInicioNavesEnemigasNodriza + FVector(0.0f, 200.0f, 0.0f);
			ANaveEnemigaNodriza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionInicioNavesEnemigasNodriza, rotacionInicioNavesEnemigasNodriza);
		}

	}

	Ingeniero = GetWorld()->SpawnActor<AIngenieroEspecialista1>(AIngenieroEspecialista1::StaticClass());
	Director = GetWorld()->SpawnActor<ADirectorBuilder>(ADirectorBuilder::StaticClass());

	Director->OrdenarIngeniero(Ingeniero);
	Director->ConstruirNaveEscudo();

	AConstruirNaveEnemiga* NaveEnemiga = Director->ObtenerNave();
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
	}
	else if (_Orden.Equals("Velocidad"))
	{
		CrearCapsulaDeVelocidad();
	}
	else if (_Orden.Equals("SinCapsulas"))
	{
		BloquearCapsula();
	}
	else if (_Orden.Equals("Escuadron1"))
	{
		CrearEscuadronEnemigos1();
	}
	else if (_Orden.Equals("Escuadron2"))
	{
		CrearEscuadronEnemigos2();
	}
	else if (_Orden.Equals("Escuadron3"))
	{
		CrearEscuadronEnemigos3();
	}
}

// Called every frame
void ACapsulasTipoFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


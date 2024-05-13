// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdapterPatern1GameMode.h"
#include "AdapterPatern1Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "BallAdapter.h"
//PatronBuilder
#include "IngenieroEspecialista1.h"
#include "IngenieroEspecialista2.h"
#include "IngenieroEspecialista3.h"
#include "DirectorBuilder.h"
#include "ConstruirNaveEnemiga.h"

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


	FVector PosCaza = FVector(-600.0f, -600.0f, 250.0f);
	FVector PosTransporte = FVector(-400.0f, -600.0f, 250.0f);
	FVector PosDestructor = FVector(-200.0f, -600.0f, 250.0f);

	FVector ubicacionInicioNavesEnemigasCaza = FVector(0.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasCaza = FRotator(0.0f, 180.0f, 0.0f);

	FVector ubicacionInicioNavesEnemigasTransporte = FVector(300.0f, -500.0f, 200.0f);
	FRotator rotacionInicioNavesEnemigasTransporte = FRotator(0.0f, 180.0f, 0.0f);

	//Patron Builder

	Ingeniero = GetWorld()->SpawnActor<AIngenieroEspecialista1>(AIngenieroEspecialista1::StaticClass());
	Director = GetWorld()->SpawnActor<ADirectorBuilder>(ADirectorBuilder::StaticClass());

	Director->OrdenarIngeniero(Ingeniero);
	Director->ConstruirNaveEscudo();

	AConstruirNaveEnemiga* NaveEnemiga = Director->ObtenerNave();

	Ingeniero2 = GetWorld()->SpawnActor<AIngenieroEspecialista2>(AIngenieroEspecialista2::StaticClass());

	Director->OrdenarIngeniero(Ingeniero2);
	Director->ConstruirNaveEscudo();

	AConstruirNaveEnemiga* NaveEnemiga2 = Director->ObtenerNave();


	Ingeniero3 = GetWorld()->SpawnActor<AIngenieroEspecialista3>(AIngenieroEspecialista3::StaticClass());

	Director->OrdenarIngeniero(Ingeniero3);
	Director->ConstruirNaveBatalla();

	AConstruirNaveEnemiga* NaveEnemiga3 = Director->ObtenerNave();



	UWorld* const World = GetWorld();

	if (World != nullptr)
	{

		/*ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 600.0f, 0.0f);
		ANaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicioNavesEnemigasCaza, rotacionInicioNavesEnemigasCaza);


		ubicacionInicioNavesEnemigasCaza = ubicacionInicioNavesEnemigasCaza + FVector(0.0f, 200.0f, 0.0f);*/



		//for (int i = 0; i < 5; i++)
		//{
		//	ubicacionInicioNavesEnemigasTransporte = ubicacionInicioNavesEnemigasTransporte + FVector(0.0f, 200.0f, 0.0f);
		//	ANaveEnemigaTransporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionInicioNavesEnemigasTransporte, rotacionInicioNavesEnemigasTransporte);
		//	
		//}

			/*	for (int i = 0; i < 5; i++)
				{
					ubicacionInicioNavesEnemigasTransporte = ubicacionInicioNavesEnemigasTransporte + FVector(0.0f, 200.0f, 0.0f);
					ANaveEnemigaTransporte* NaveEnemigaTemporal = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionInicioNavesEnemigasTransporte, rotacionInicioNavesEnemigasTransporte);

				}*/
	}
}

void AAdapterPatern1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimerController += DeltaTime;

	/*if (TimerController >= 5.0f)
	{
		Director->ConstruirPaqueteEnergia(Cont);
		TimerController = 0.0f;
		Cont++;
		if (Cont > 3)
		{
			Cont = 1;
		}
	}*/
}

void AAdapterPatern1GameMode::ActualizarPosicionesNavesEnemigas()
{
	//for (ANaveEnemiga* NaveEnemiga : TANavesEnemigas)
	//{
	//	TMPosicionesNavesEnemigas.Add(NaveEnemiga, NaveEnemiga->GetActorLocation());
	//}
}

void AAdapterPatern1GameMode::MostrarPosicionesNavesEnemigas()
{
	/*for (auto ElementoActual : TMPosicionesNavesEnemigas) {
		ANaveEnemiga* naveEnemigaActual = ElementoActual.Key;
		FVector posicionActualNaveEnemiga = ElementoActual.Value;
		FString mensaje = "La nave " + naveEnemigaActual->GetNombre() + " esta en la posicion> " + posicionActualNaveEnemiga.ToString();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, mensaje);

			/*FString mensaje = "Nombre NaveEnemiga: " + Clave->GetNombre() + " Posicion NaveEnemiga: " + Valor.ToString();
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mensaje);*

		}

		TMPosicionesNavesEnemigas[naveEnemigaActual] = naveEnemigaActual->GetActorLocation();
	}*/
}

void AAdapterPatern1GameMode::EliminarNavesEnemigas()
{
	//for (ANaveEnemiga* NaveEnemiga : TANavesEnemigas)
	//{
	//	NaveEnemiga->Destroy();
	//}
	//TANavesEnemigas.Empty();
}

void AAdapterPatern1GameMode::CrearNavesEnemigas()
{
	/*UWorld* const World = GetWorld();
if (World != nullptr)
{
	FVector ubicacionInicialNavesEnemigas = FVector(0.0f, 0.0f, 150.0f);
	FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < 3; i++)
	{
		ANaveEnemiga* NuevaNaveEnemiga = nullptr;

		int32 TipoAleatorio = FMath::RandRange(0, 1);

		if (TipoAleatorio == 0)
		{
			NuevaNaveEnemiga = World->SpawnActor<ANaveEnemigaCaza>(ubicacionInicialNavesEnemigas, rotacionNave);
		}
		else
		{
			NuevaNaveEnemiga = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionInicialNavesEnemigas, rotacionNave);
		}

		NuevaNaveEnemiga->SetNombre("Nave Enemiga " + FString::FromInt(i));
		TANavesEnemigas.Add(NuevaNaveEnemiga);
		TMPosicionesNavesEnemigas.Add(NuevaNaveEnemiga, ubicacionInicialNavesEnemigas);

		ubicacionInicialNavesEnemigas.Y += 150.0f;
	}
}*/
}

void AAdapterPatern1GameMode::DetenerProceso()
{
	/*Detener Todos los timers*/

	//GetWorldTimerManager().ClearTimer(ManejadorEliminarNaves);
	//GetWorldTimerManager().ClearTimer(ManejadorCrearNaves);
	//GetWorldTimerManager().ClearTimer(ManejadorMostrarPosiciones);
	//GetWorldTimerManager().ClearTimer(ManejadorDetenerProceso);
}


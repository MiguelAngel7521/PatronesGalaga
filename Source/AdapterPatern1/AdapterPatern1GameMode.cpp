// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdapterPatern1GameMode.h"
#include "AdapterPatern1Pawn.h"
#include "Kismet/GameplayStatics.h"
//Patron Adapter
#include "BallAdapter.h"
//Patron Fabrica
#include "FabricaNaveEnemigas.h"
//Patron Builder
#include "IngenieroEspecialista1.h"
#include "IngenieroEspecialista2.h"
#include "IngenieroEspecialista3.h"
#include "DirectorBuilder.h"
#include "ConstruirNaveEnemiga.h"
//Patron Facade
#include "CapsulasFacade.h"

AAdapterPatern1GameMode::AAdapterPatern1GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAdapterPatern1Pawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
}

void AAdapterPatern1GameMode::BeginPlay()
{
	Super::BeginPlay();

	//Patron Adapter
	Jugador = GetWorld()->SpawnActor<AAdapterPatern1Pawn>(AAdapterPatern1Pawn::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);
	Jugador = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Adapter = GetWorld()->SpawnActor<ABallAdapter>(ABallAdapter::StaticClass(),FVector(0,0,0),FRotator::ZeroRotator);
	Jugador->SetBounceBall(Adapter);
    Jugador->Lanzar();


	//Patron Builder

	/*Ingeniero = GetWorld()->SpawnActor<AIngenieroEspecialista1>(AIngenieroEspecialista1::StaticClass());
	Director = GetWorld()->SpawnActor<ADirectorBuilder>(ADirectorBuilder::StaticClass());

	Director->OrdenarIngeniero(Ingeniero);
	Director->ConstruirNaveEscudo();

	AConstruirNaveEnemiga* NaveEnemiga = Director->ObtenerNave();*/

	/*Ingeniero2 = GetWorld()->SpawnActor<AIngenieroEspecialista2>(AIngenieroEspecialista2::StaticClass());

	Director->OrdenarIngeniero(Ingeniero2);
	Director->ConstruirNaveEscudo();

	AConstruirNaveEnemiga* NaveEnemiga2 = Director->ObtenerNave();*/


	/*Ingeniero3 = GetWorld()->SpawnActor<AIngenieroEspecialista3>(AIngenieroEspecialista3::StaticClass());

	Director->OrdenarIngeniero(Ingeniero3);
	Director->ConstruirNaveBatalla();

	AConstruirNaveEnemiga* NaveEnemiga3 = Director->ObtenerNave();*/


	//Patron Facade de capsulas

	Facade = GetWorld()->SpawnActor<ACapsulasFacade>(ACapsulasFacade::StaticClass());
	Facade->NivelDificil();


	//Patron Factory
	
	
	//FVector ubicacionInicialNavesEnemigas = FVector(2300.0f, -510.0f, 240);
	//FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
	//FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);


	//UWorld* const World = GetWorld();
	//const TArray<FVector>;

	//if (World != nullptr)
	//{
	//	const int32 MaxNaves = 15;
	//	const int32 NumTiposNaves = 4; // Caza, Transporte, Espia, Nodriza 
	//	const int32 MaxNavesPorTipo = MaxNaves / NumTiposNaves;

	//	TArray<ANaveEnemiga*> NavesEnemigas;

	//	for (int i = 0; i < 10; ++i)
	//	{
	//		int32 TipoNave = FMath::RandRange(0, 3); // Random entre 0 y 3 para los 4 tipos de naves

	//		FString NombreNave = "Nave Enemiga " + FString::FromInt(i);

	//		ANaveEnemiga* NuevaNaveEnemiga = AFabricaNaveEnemigas::FabricarNave(TipoNave == 0 ? "Caza" : TipoNave == 1 ? "Transporte" : TipoNave == 2 ? "Espia" : "Nodriza", this);

	//		if (NuevaNaveEnemiga)
	//		{
	//			NuevaNaveEnemiga->SetNombre(NombreNave);
	//			NuevaNaveEnemiga->SetActorLocation(ubicacionInicialNavesEnemigas);
	//			NuevaNaveEnemiga->SetActorRotation(rotacionNave);
	//			NuevaNaveEnemiga->FinishSpawning(FTransform(rotacionNave, ubicacionInicialNavesEnemigas));

	//			World->SpawnActor(NuevaNaveEnemiga->GetClass(), &ubicacionInicialNavesEnemigas, &rotacionNave);


	//			ubicacionActualNaveEnemiga.Y += 800.0f;
	//			ubicacionActualNaveEnemiga.X = 0.0f;
	//			ubicacionActualNaveEnemiga.Z = 240.0f;
	//		}
	//		else
	//		{
	//			UE_LOG(LogTemp, Warning, TEXT("No se pudo crear la nave enemiga %s"), *NombreNave);
	//		}
	//	}
	//}
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





void AAdapterPatern1GameMode::DetenerProceso()
{
	/*Detener Todos los timers*/

	//GetWorldTimerManager().ClearTimer(ManejadorEliminarNaves);
	//GetWorldTimerManager().ClearTimer(ManejadorCrearNaves);
	//GetWorldTimerManager().ClearTimer(ManejadorMostrarPosiciones);
	//GetWorldTimerManager().ClearTimer(ManejadorDetenerProceso);
}


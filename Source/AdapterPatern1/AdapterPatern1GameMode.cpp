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
//Patron Observer
#include "RadarEnemigo.h"
#include "ArmaAmiga.h"
//Patron Strategy
#include "EstrategiaAtaqueFinal.h"
#include "EstrategiaCamaraLenta.h"
#include "EstrategiaExplosiva.h"
#include "EstrategiaRecuperacion.h"
//Patron Proxy
#include "ProxyNaveCompuesta.h"


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
	Jugador = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Adapter = GetWorld()->SpawnActor<ABallAdapter>(ABallAdapter::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);
	Jugador->SetBounceBall(Adapter);
	Jugador->Lanzar();

	//Patron State

	//Inicilaiamos el estado basico

	Jugador->InicializarEstadosJugador("Basico");
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("%s"), *Jugador->J_ObtenerEstadoActual()));*/
	Jugador->JugadorBasico();



	//patron Observer
	Radar = GetWorld()->SpawnActor<ARadarEnemigo>(ARadarEnemigo::StaticClass());




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

	//Patron Strategy


	/*EstrategiaRecuperacion = GetWorld()->SpawnActor<AEstrategiaRecuperacion>(AEstrategiaRecuperacion::StaticClass());
	EstrategiaExplosiva = GetWorld()->SpawnActor<AEstrategiaExplosiva>(AEstrategiaExplosiva::StaticClass());
	EstrategiaAtaqueFinal = GetWorld()->SpawnActor<AEstrategiaAtaqueFinal>(AEstrategiaAtaqueFinal::StaticClass());
	EstrategiaCamaraLenta = GetWorld()->SpawnActor<AEstrategiaCamaraLenta>(AEstrategiaCamaraLenta::StaticClass());*/

	//// Obtener la ubicación y rotación del pawn
	FVector PawnLocation = Jugador->GetActorLocation();
	PawnLocation.Y += 200.0f;
	FRotator PawnRotation = Jugador->GetActorRotation();

	
	AArmaAmiga* ArmaIzquierda = GetWorld()->SpawnActor<AArmaAmiga>(PawnLocation , PawnRotation);
	if (ArmaIzquierda)
	{
		// Anclar el arma al jugador con las reglas de anclaje deseadas
		ArmaIzquierda->AttachToActor(Jugador, FAttachmentTransformRules::KeepWorldTransform);

		// Ajustar la ubicación del arma después de anclarla
		FVector NewRelativeLocation = ArmaIzquierda->GetActorLocation();
		NewRelativeLocation.Y += 0.0f;
		ArmaIzquierda->SetActorLocation(NewRelativeLocation);
	}
	//Patron Proxy
	   // Crear y configurar el proxy para la nave compuesta
	AProxyNaveCompuesta* Proxy = GetWorld()->SpawnActor<AProxyNaveCompuesta>(AProxyNaveCompuesta::StaticClass());

	//Patron Factory
	
	
	//FVector ubicacionInicialNavesEnemigas = FVector(670.0f, -460.0f, 240);
	//FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
	//FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);


	//UWorld* const World = GetWorld();
	//const TArray<FVector>;

	//if (World != nullptr)
	//{
	//	AFabricaNaveEnemigas::FabricarNave("Caza", 25, 5, ubicacionActualNaveEnemiga, World);

	//	//AFabricaNaveEnemigas::FabricarNave("Transporte", 10, 5, ubicacionActualNaveEnemiga, World);
	//	//AFabricaNaveEnemigas::FabricarNave("Nodriza", 10, 5, ubicacionActualNaveEnemiga, World);
	//	//AFabricaNaveEnemigas::FabricarNave("Espia", 10, 5, ubicacionActualNaveEnemiga, World);
	//}
}

void AAdapterPatern1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimerController += DeltaTime;

	
}





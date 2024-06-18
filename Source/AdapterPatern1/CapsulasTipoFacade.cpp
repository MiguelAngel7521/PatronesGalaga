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
#include "RecuperacionVisitor.h"
#include "MovimientoVisitor.h"
#include "FabricaNaveEnemigas.h"
#include "FabricaCapsulas.h"
#include "FabricaObstaculos.h"	
#include "Obstaculo.h"
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
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACapsulasTipoFacade::CrearObstaculos, 20.0f, false);
	
}

void ACapsulasTipoFacade::CrearCapsulaDeVida()
{
	AFabricaCapsulas* FabricaCapsulas = GetWorld()->SpawnActor<AFabricaCapsulas>(AFabricaCapsulas::StaticClass());
	FabricaCapsulas->GenerarCapsula();
	/*FVector PosicionCapsulaVida = FVector(-990.0f, -160.0f, 250.0f);
	FRotator RotacionCapsulaVida = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeVida = GetWorld()->SpawnActor<ACapsulaVida>(ACapsulaVida::StaticClass());
	CapsulaDeVida->SetActorLocation(PosicionCapsulaVida);
	CapsulaDeVida->SetActorRotation(RotacionCapsulaVida);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Creando capsula de vida")));*/

}

void ACapsulasTipoFacade::CrearCapsulaDeEnergia()
{
	AFabricaCapsulas* FabricaCapsulas = GetWorld()->SpawnActor<AFabricaCapsulas>(AFabricaCapsulas::StaticClass());
	FabricaCapsulas->GenerarCapsula();
	//FVector PosicionCapsulaEnergia = FVector(-990.0f, -260.0f, 250.0f);
	//FRotator RotacionCapsulaEnergia = FRotator(0.0f, 0.0f, 0.0f);

	//CapsulaDeEnergia = GetWorld()->SpawnActor<ACapsulaEnergia>(ACapsulaEnergia::StaticClass());
	//CapsulaDeEnergia->SetActorLocation(PosicionCapsulaEnergia);
	//CapsulaDeEnergia->SetActorRotation(RotacionCapsulaEnergia);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Creando capsula de Energia")));
}

void ACapsulasTipoFacade::CrearCapsulaDeVelocidad()
{
	AFabricaCapsulas* FabricaCapsulas = GetWorld()->SpawnActor<AFabricaCapsulas>(AFabricaCapsulas::StaticClass());
	FabricaCapsulas->GenerarCapsula();
	/*FVector PosicionCapsulaVelocidad = FVector(-990.0f, -360.0f, 250.0f);
	FRotator RotacionCapsulaVelocidad = FRotator(0.0f, 0.0f, 0.0f);

	CapsulaDeVelocidad = GetWorld()->SpawnActor<ACapsulaVelocidad>(ACapsulaVelocidad::StaticClass());
	CapsulaDeVelocidad->SetActorLocation(PosicionCapsulaVelocidad);
	CapsulaDeVelocidad->SetActorRotation(RotacionCapsulaVelocidad);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Creando capsula de velocidad")));*/
}

void ACapsulasTipoFacade::BloquearCapsula()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Sin Capsulas")));
}

void ACapsulasTipoFacade::CrearEscuadronEnemigos1()
{

	FVector ubicacionInicialNavesEnemigasCaza = FVector(1310.0f, -1190.0f, 240);
	FVector ubicacionInicialNavesEnemigasTransporte = FVector(150.0f, -450.0f, 240);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		AFabricaNaveEnemigas::FabricarNave("Caza", 5, 2, ubicacionInicialNavesEnemigasCaza, World);
		AFabricaNaveEnemigas::FabricarNave("Transporte", 3, 2, ubicacionInicialNavesEnemigasTransporte, World);
	}
	
}

void ACapsulasTipoFacade::CrearEscuadronEnemigos2()
{
	FVector ubicacionInicialNavesEnemigasCaza = FVector(1310.0f, -1190.0f, 240);
	FVector ubicacionInicialNavesEnemigasTransporte = FVector(150.0f, -450.0f, 240);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(1310.0f, 800.0f, 200.0f);


	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		AFabricaNaveEnemigas::FabricarNave("Caza", 10, 5, ubicacionInicialNavesEnemigasCaza, World);
		AFabricaNaveEnemigas::FabricarNave("Transporte", 10, 5, ubicacionInicialNavesEnemigasTransporte, World);
		AFabricaNaveEnemigas::FabricarNave("Espia", 10, 5, ubicacionInicioNavesEnemigasEspia, World);
	}

}

void ACapsulasTipoFacade::CrearEscuadronEnemigos3()
{
	FVector ubicacionInicialNavesEnemigasCaza = FVector(1310.0f, -1190.0f, 240);
	FVector ubicacionInicialNavesEnemigasTransporte = FVector(150.0f, -450.0f, 240);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(1310.0f, 800.0f, 200.0f);
	FVector ubicacionInicioNavesEnemigasNodriza = FVector(150.0f, 1000.0f, 200.0f);

	

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		AFabricaNaveEnemigas::FabricarNave("Caza", 15, 5, ubicacionInicialNavesEnemigasCaza, World);
		AFabricaNaveEnemigas::FabricarNave("Transporte", 15, 5, ubicacionInicialNavesEnemigasTransporte, World);
		AFabricaNaveEnemigas::FabricarNave("Espia", 15, 5, ubicacionInicioNavesEnemigasEspia, World);
		AFabricaNaveEnemigas::FabricarNave("Nodriza", 15, 5, ubicacionInicioNavesEnemigasNodriza, World);

	}
}

void ACapsulasTipoFacade::CrearObstaculos()
{
  AFabricaObstaculos* FabricaObstaculos = GetWorld()->SpawnActor<AFabricaObstaculos>(AFabricaObstaculos::StaticClass());
  FabricaObstaculos->GenerarObstaculos(3, FVector(-1000.0f, -1000.0f, 200.0f), FVector(1000.0f, 1000.0f, 200.0f), 100.0f, 200.0f);
  GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Creando obstaculos")));
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
	else if (_Orden.Equals("Obstaculo1"))
	{
		CrearObstaculos();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Orden no reconocida")));
	}
}

// Called every frame
void ACapsulasTipoFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}






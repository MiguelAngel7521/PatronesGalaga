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
#include "ProxyNaveCompuesta.h"
#include "AdapterPatern1Pawn.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

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
	IniciarCreacionCapsulas();
	
}

void ACapsulasTipoFacade::CrearCapsulaDeVida()
{
	AFabricaCapsulas* FabricaCapsulas = GetWorld()->SpawnActor<AFabricaCapsulas>(AFabricaCapsulas::StaticClass());
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);  // Assuming the player pawn is at index 0
	FabricaCapsulas->GenerarCapsula(PlayerPawn, ACapsulaVida::StaticClass());


}

void ACapsulasTipoFacade::CrearCapsulaDeEnergia()
{
	AFabricaCapsulas* FabricaCapsulas = GetWorld()->SpawnActor<AFabricaCapsulas>(AFabricaCapsulas::StaticClass());
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FabricaCapsulas->GenerarCapsula(PlayerPawn, ACapsulaEnergia::StaticClass());
}

void ACapsulasTipoFacade::CrearCapsulaDeVelocidad()
{
	AFabricaCapsulas* FabricaCapsulas = GetWorld()->SpawnActor<AFabricaCapsulas>(AFabricaCapsulas::StaticClass());
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FabricaCapsulas->GenerarCapsula(PlayerPawn, ACapsulaVelocidad::StaticClass());
	
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
	FVector ubicacionInicialNavesEnemigasTransporte = FVector(150.0f, -450.0f, 1000);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(1310.0f, 800.0f, 200.0f);


	FVector ubicacionDungeon = FVector(8430.0f, -60.0f, 200.0f);
	FVector ubicacionDungeon2 = FVector(6430.0f, -600.0f, 200.0f);



	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		AFabricaNaveEnemigas::FabricarNave("Caza", 5, 2, ubicacionInicialNavesEnemigasCaza, World);
		AFabricaNaveEnemigas::FabricarNave("Transporte", 5, 2, ubicacionInicialNavesEnemigasTransporte, World);
		AFabricaNaveEnemigas::FabricarNave("Espia", 5, 2, ubicacionInicioNavesEnemigasEspia, World);
	}

}

void ACapsulasTipoFacade::CrearEscuadronEnemigos3()
{
	FVector ubicacionInicialNavesEnemigasCaza = FVector(1310.0f, -1190.0f, 240);
	FVector ubicacionInicialNavesEnemigasTransporte = FVector(150.0f, -450.0f, 240);

	FVector ubicacionInicioNavesEnemigasEspia = FVector(1310.0f, 400.0f, 200.0f);
	FVector ubicacionInicioNavesEnemigasNodriza = FVector(150.0f, 1000.0f, 200.0f);

	

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		AFabricaNaveEnemigas::FabricarNave("Caza", 5, 2, ubicacionInicialNavesEnemigasCaza, World);
		AFabricaNaveEnemigas::FabricarNave("Transporte", 5, 2, ubicacionInicialNavesEnemigasTransporte, World);
		AFabricaNaveEnemigas::FabricarNave("Espia", 5, 2, ubicacionInicioNavesEnemigasEspia, World);
		AFabricaNaveEnemigas::FabricarNave("Nodriza", 5, 2, ubicacionInicioNavesEnemigasNodriza, World);

	}
}

void ACapsulasTipoFacade::CrearObstaculos()
{
	AFabricaObstaculos* FabricaObstaculos = GetWorld()->SpawnActor<AFabricaObstaculos>(AFabricaObstaculos::StaticClass());
	AAdapterPatern1Pawn* PlayerPawn = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)); // Assuming the player pawn is at index 0
	FabricaObstaculos->GenerarObstaculos(3, FVector(-50.0f, -700.0f, 200.0f), FVector(50.0f, 700.0f, 200.0f), 100.0f, 200.0f, PlayerPawn);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Creando obstaculos")));
}

void ACapsulasTipoFacade::IniciarCreacionCapsulas()
{
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandleCapsulaVida, this, &ACapsulasTipoFacade::CrearCapsulaDeVida, 15.0f, true);
	GetWorld()->GetTimerManager().SetTimer(TimerHandleCapsulaEnergia, this, &ACapsulasTipoFacade::CrearCapsulaDeEnergia, 35.0f, true);
	GetWorld()->GetTimerManager().SetTimer(TimerHandleCapsulaVelocidad, this, &ACapsulasTipoFacade::CrearCapsulaDeVelocidad, 40.0f, true);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACapsulasTipoFacade::CrearObstaculos, 30.0f, true);

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






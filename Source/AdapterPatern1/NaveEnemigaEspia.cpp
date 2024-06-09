// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"
#include "AdapterPatern1Projectile.h"
//Patron Observer
#include "RadarHDU.h"
#include "IObserverRadar.h"
#include "Engine/World.h"
#include "EngineUtils.h"
//Patron Visitor
#include "INaveEnemigaVisitor.h"
#include "RecuperacionVisitor.h"
#include "MovimientoVisitor.h"
#include "AtaqueVisitor.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NavesEnemigas.NavesEnemigas'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
	mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
	mallaNaveEnemiga->BodyInstance.SetCollisionProfileName("NaveEnemiga");
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaEspia::OnHit);


	escudo = 100;
	Sigilo = 100;
	consumo_de_energia = 10;
	Armamento = 10;

	// Tag
	Tags.Add(FName("Radar"));
	// Asignar coordenadas de destino
	targetLocations.Add(FVector(-300, 1600, 200));    // Coordenada 1
	targetLocations.Add(FVector(-880, 1000, 200));  // Coordenada 2
	targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
	targetLocations.Add(FVector(-880, 40, 200));  // Coordenada 4
	targetLocations.Add(FVector(-510, -480, 200));  // Coordenada 5
	targetLocations.Add(FVector(-880, -950, 200));    // Coordenada 6
	targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7

	// Set the initial target location index

	currentTargetIndex = 0;
}

void ANaveEnemigaEspia::BeginPlay()
{
	Super::BeginPlay();

	//Suscribirse a todos los radares
	for (TActorIterator<ARadarHDU> It(GetWorld()); It; ++It)
	{
		SuscribirRadar(*It);
	}
	//Patron Visitor
	MovimientoVisitor = Cast<AMovimientoVisitor>(GetWorld()->SpawnActor(AMovimientoVisitor::StaticClass()));
	RecuperacionVisitor = Cast<ARecuperacionVisitor>(GetWorld()->SpawnActor(ARecuperacionVisitor::StaticClass()));
	AtaqueVisitor = Cast<AAtaqueVisitor>(GetWorld()->SpawnActor(AAtaqueVisitor::StaticClass()));
}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	//Notificar ala radar cada segundo
	NotificarRadar();
	//patron visitor

	if (MovimientoVisitor)
	{
		MovimientoVisitor->VisitNaveEnemigaEspia(this);
	}
	if (RecuperacionVisitor)
	{
		RecuperacionVisitor->VisitNaveEnemigaEspia(this);
	}
	if (AtaqueVisitor)
	{
		AtaqueVisitor->VisitNaveEnemigaEspia(this);
	}
	
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();
	float NuevaX = FMath::RandRange(-1000, 1000) * DeltaTime;
	float NuevaY = FMath::RandRange(-1000, 1000) * DeltaTime;
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);
	NuevaPosicion.X = NuevaPosicion.X + Sigilo * DeltaTime;
	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaEspia::ActivarSigilo()
{
	Sigilo = Sigilo - consumo_de_energia;
}

void ANaveEnemigaEspia::DesactivarSigilo()
{
	Sigilo = Sigilo + consumo_de_energia;
}

void ANaveEnemigaEspia::RecopilarInformacion()
{
}

void ANaveEnemigaEspia::InterceptarComunicaciones()
{
}

void ANaveEnemigaEspia::SuscribirRadar(AActor* RadarHDU)
{
	if (RadarHDU->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
	{
		Observers.Add(RadarHDU);
		UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *RadarHDU->GetName());
	}
}

void ANaveEnemigaEspia::NotificarRadar()
{
	for (AActor* Observer : Observers)
	{
		IIObserverRadar* ObserverInterface = Cast<IIObserverRadar>(Observer);
		if (ObserverInterface)
		{
			ObserverInterface->UpdatePosition(this);
			UE_LOG(LogTemp, Warning, TEXT("Notificando radar: %s con Actor: %s"), *Observer->GetName(), *this->GetName());
		}
	}
}

void ANaveEnemigaEspia::Accept(IINaveEnemigaVisitor* Visitor)
{
	Visitor->VisitNaveEnemigaEspia(this);
}





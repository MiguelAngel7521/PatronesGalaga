// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"
//Patron Observer
#include "RadarHDU.h"
#include "IObserverRadar.h"
#include "Engine/World.h"
#include "EngineUtils.h"

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Notificar ala radar cada segundo 
	NotificarRadar();
	// Calculate the new position based on the current direction and speed
	FVector newLocation = GetActorLocation();
	FVector targetLocation = targetLocations[currentTargetIndex];
	FVector direction = (targetLocation - newLocation).GetSafeNormal();
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * speed * DeltaTime;

	SetActorLocation(newLocation);

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (distance < 10.0f)
	{
		// Mover a la siguiente ubicación de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
	}
}

void ANaveEnemigaTransporte::DescargarContenido()
{
}

void ANaveEnemigaTransporte::ActivarArmasDefensivas()
{
}

void ANaveEnemigaTransporte::RecogerRecursos()
{
}

void ANaveEnemigaTransporte::IntercambiarRecursos()
{
}

void ANaveEnemigaTransporte::ReabastecerNaves()
{
}

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NavesEnemigas.NavesEnemigas'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
	mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
	mallaNaveEnemiga->BodyInstance.SetCollisionProfileName("NaveEnemiga");
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaTransporte::OnHit);

	TiempoDescarga = 10;
	ArmasDefensivas = 10;
	CapacidadCarga = 100;
	//Tag
	Tags.Add(FName("Radar"));
	// Asignar coordenadas de destino
	targetLocations.Add(FVector(-300, 1600, 200));    // Coordenada 1
	targetLocations.Add(FVector(-700, 1000, 200));  // Coordenada 2
	targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
	targetLocations.Add(FVector(-700, 40, 200));  // Coordenada 4
	targetLocations.Add(FVector(-510, -480, 200));  // Coordenada 5
	targetLocations.Add(FVector(-700, -950, 200));    // Coordenada 6
	targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();
	float NuevaX = FMath::RandRange(0.0f, 0.0f) * DeltaTime;
	float NuevaY = FMath::RandRange(0.0f, 0.0f) * DeltaTime;
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaTransporte::BeginPlay()
{
	Super::BeginPlay();
	//Suscribir al radar
	for (TActorIterator<ARadarHDU> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ARadarHDU* RadarHDU = *ActorItr;
		SuscribirRadar(RadarHDU);
	}
}

void ANaveEnemigaTransporte::SuscribirRadar(AActor* RadarHDU)
{
	if (RadarHDU->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
	{
		Observers.Add(RadarHDU);
		UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *RadarHDU->GetName());
	}
}

void ANaveEnemigaTransporte::NotificarRadar()
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

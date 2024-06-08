// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
//Patron Observer
#include "RadarHDU.h"
#include "IObserverRadar.h"
#include "Engine/World.h"
#include "EngineUtils.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NavesEnemigas.NavesEnemigas'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
	mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
	mallaNaveEnemiga->BodyInstance.SetCollisionProfileName("NaveEnemiga");
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaNodriza::OnHit);



	Escudos = 100;
	AtaqueFinal = 100;
	tripulacion = 100;
	ataqueEspecial = 100;

	//Tag
	Tags.Add(FName("Radar"));	
	// Asignar coordenadas de destino
	targetLocations.Add(FVector(-300, 2000, 200));    // Coordenada 1
	targetLocations.Add(FVector(-400, 1500, 200));  // Coordenada 2
	targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
	targetLocations.Add(FVector(-400, 40, 200));  // Coordenada 4
	targetLocations.Add(FVector(-50, -480, 200));  // Coordenada 5
	targetLocations.Add(FVector(-400, -950, 200));    // Coordenada 6
	targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7
}

void ANaveEnemigaNodriza::BeginPlay()
{
		Super::BeginPlay();
		// Suscribir el radar
		for (TActorIterator<ARadarHDU> It(GetWorld()); It; ++It)
		{
			SuscribirRadar(*It);
		}
}



void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
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



void ANaveEnemigaNodriza::DesplegarNavesPequenas()
{
}

void ANaveEnemigaNodriza::GenerarEscudos()
{
}

void ANaveEnemigaNodriza::LanzarAtaqueFinal()
{
}

void ANaveEnemigaNodriza::ReabastecerEnergia()
{
}

void ANaveEnemigaNodriza::DefenderTripulacion()
{
}

void ANaveEnemigaNodriza::SuscribirRadar(AActor* RadarHDU)
{
	if (RadarHDU->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
	{
		Observers.Add(RadarHDU);
		UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *RadarHDU->GetName());
	}
}

void ANaveEnemigaNodriza::NotificarRadar()
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

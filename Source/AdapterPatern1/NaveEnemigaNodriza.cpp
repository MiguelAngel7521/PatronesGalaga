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

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();
	float NuevaX = FMath::RandRange(-1000, 1000) * DeltaTime;
	float NuevaY = FMath::RandRange(-1000, 1000) * DeltaTime;
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);
	NuevaPosicion.X = NuevaPosicion.X + 100 * DeltaTime;
	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	//Notificar ala radar cada segundo
	NotificarRadar();
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

void ANaveEnemigaNodriza::SuscribirRadar(AActor* Radar)
{
	if (Radar->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
	{
		Observers.Add(Radar);
		UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *Radar->GetName());
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

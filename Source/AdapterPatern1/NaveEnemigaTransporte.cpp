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
		ARadarHDU* Radar = *ActorItr;
		SuscribirRadar(Radar);
	}
}

void ANaveEnemigaTransporte::SuscribirRadar(AActor* Radar)
{
	if (Radar->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
	{
		Observers.Add(Radar);
		UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *Radar->GetName());
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

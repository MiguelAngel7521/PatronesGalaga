// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"
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

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Notificar ala radar cada segundo 
	NotificarRadar();
	//patron visitor

	if (MovimientoVisitor)
	{
		MovimientoVisitor->VisitNaveEnemigaTransporte(this);
	}
	if (RecuperacionVisitor)
	{
		RecuperacionVisitor->VisitNaveEnemigaTransporte(this);
	}
	if (AtaqueVisitor)
	{
		AtaqueVisitor ->VisitNaveEnemigaTransporte(this);
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

}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
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
	//Patron Visitor
	MovimientoVisitor = Cast<AMovimientoVisitor>(GetWorld()->SpawnActor(AMovimientoVisitor::StaticClass()));
	RecuperacionVisitor = Cast<ARecuperacionVisitor>(GetWorld()->SpawnActor(ARecuperacionVisitor::StaticClass()));
	AtaqueVisitor = Cast<AAtaqueVisitor>(GetWorld()->SpawnActor(AAtaqueVisitor::StaticClass()));
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

void ANaveEnemigaTransporte::Accept(IINaveEnemigaVisitor* Visitor)
{
	Visitor->VisitNaveEnemigaTransporte(this);
}

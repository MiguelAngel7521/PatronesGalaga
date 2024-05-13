// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	//mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
	Escudos = 100;
	AtaqueFinal = 100;
	tripulacion = 100;
	ataqueEspecial = 100;
}

void ANaveEnemigaNodriza::BeginPlay()
{
		Super::BeginPlay();
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

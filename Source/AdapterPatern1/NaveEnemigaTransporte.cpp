// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);*/
	TiempoDescarga = 10;
	ArmasDefensivas = 10;
	CapacidadCarga = 100;
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();
	float NuevaX = FMath::RandRange(0.0f, 0.0f) * DeltaTime;
	float NuevaY = FMath::RandRange(0.0f, 0.0f) * DeltaTime;
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	SetActorLocation(NuevaPosicion);
}

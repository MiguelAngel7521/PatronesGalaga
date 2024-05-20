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
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NavesEnemigas.NavesEnemigas'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
	mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
	mallaNaveEnemiga->BodyInstance.SetCollisionProfileName("NaveEnemiga");
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaTransporte::OnHit);

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

// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);*/
	escudo = 100;
	Sigilo = 100;
	consumo_de_energia = 10;
	Armamento = 10;
}

void ANaveEnemigaEspia::BeginPlay()
{
	Super::BeginPlay();
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

void ANaveEnemigaEspia::DestruirNaveEnemiga()
{
	Destroy();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "RecuperacionVisitor.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaTransporte.h"

// Sets default values
ARecuperacionVisitor::ARecuperacionVisitor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARecuperacionVisitor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARecuperacionVisitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARecuperacionVisitor::VisitNaveEnemigaCaza(ANaveEnemigaCaza* Nave)
{
	if (Nave->Energia == 0) {
		Nave->Vida += 10;
		Nave->Energia += 10;
	}

}

void ARecuperacionVisitor::VisitNaveEnemigaEspia(ANaveEnemigaEspia* Nave)
{
	if (Nave->Energia == 0) {
		Nave->Vida += 10;
		Nave->Energia += 10;
	}
}

void ARecuperacionVisitor::VisitNaveEnemigaNodriza(ANaveEnemigaNodriza* Nave)
{
	if (Nave->Energia == 0) {
		Nave->Vida += 10;
		Nave->Energia += 10;
	}
}

void ARecuperacionVisitor::VisitNaveEnemigaTransporte(ANaveEnemigaTransporte* Nave)
{
	if (Nave->Energia == 0) {
		Nave->Vida += 10;
		Nave->Energia += 10;
	}
}

void ARecuperacionVisitor::VisitComponenteEscudo(AComponenteEscudo* Componente)
{
}

void ARecuperacionVisitor::VisitComponenteArmas(AComponenteArmas* Componente)
{
}


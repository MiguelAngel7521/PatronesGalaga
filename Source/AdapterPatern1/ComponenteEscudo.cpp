// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteEscudo.h"
#include "INaveEnemigaVisitor.h"
#include "RecuperacionVisitor.h"
#include "MovimientoVisitor.h"
#include "AtaqueVisitor.h"

// Sets default values
AComponenteEscudo::AComponenteEscudo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/Cylinder.Cylinder'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialEscudo(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/BlueMaterial.BlueMaterial'"));
	MallaEscudo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	MallaEscudo ->SetMaterial(0, MaterialEscudo.Object);
	MallaEscudo->SetStaticMesh(ShipMesh.Object);

}

// Called when the game starts or when spawned
void AComponenteEscudo::BeginPlay()
{
	Super::BeginPlay();
	//Patron Visitor
	MovimientoVisitor = Cast<AMovimientoVisitor>(GetWorld()->SpawnActor(AMovimientoVisitor::StaticClass()));
	RecuperacionVisitor = Cast<ARecuperacionVisitor>(GetWorld()->SpawnActor(ARecuperacionVisitor::StaticClass()));
	AtaqueVisitor = Cast<AAtaqueVisitor>(GetWorld()->SpawnActor(AAtaqueVisitor::StaticClass()));
	
}
 
// Called every frame
void AComponenteEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MovimientoVisitor)
	{
		MovimientoVisitor->VisitComponenteEscudo(this);
	}
	if (RecuperacionVisitor)
	{
		RecuperacionVisitor->VisitComponenteEscudo(this);
	}
	if (AtaqueVisitor)
	{
		AtaqueVisitor->VisitComponenteEscudo(this);
	}


}

void AComponenteEscudo::RecibirDanio()
{
		Vida--;
	if (Vida <= 0)
		{
		Destroy();
	}
}

void AComponenteEscudo::Accept(IINaveEnemigaVisitor* Visitor)
{
	Visitor->VisitComponenteEscudo(this);
}


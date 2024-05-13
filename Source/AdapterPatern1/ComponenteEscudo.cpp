// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteEscudo.h"

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
	
}

// Called every frame
void AComponenteEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


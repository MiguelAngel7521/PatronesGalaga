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
	// Asignar coordenadas de destino
	targetLocations.Add(FVector(-300, 1300, 200));    // Coordenada 1
	targetLocations.Add(FVector(-700, 1000, 200));  // Coordenada 2
	targetLocations.Add(FVector(-510, 560, 200));  // Coordenada 3
	targetLocations.Add(FVector(-700, 40, 200));  // Coordenada 4
	targetLocations.Add(FVector(-510, -480, 200));  // Coordenada 5
	targetLocations.Add(FVector(-700, -950, 200));    // Coordenada 6
	targetLocations.Add(FVector(-300, -1600, 200));    // Coordenada 7
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
	// Calculate the new position based on the current direction and speed
	FVector newLocation = GetActorLocation();
	FVector targetLocation = targetLocations[currentTargetIndex];
	FVector direction = (targetLocation - newLocation).GetSafeNormal();
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * speed * DeltaTime;

	SetActorLocation(newLocation);

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (distance < 10.0f)
	{
		// Mover a la siguiente ubicación de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
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


// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteArmas.h"
#include "ProjectileEnemigo.h"

// Sets default values
AComponenteArmas::AComponenteArmas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/NaveEnemiga.NaveEnemiga'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialArma(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/Balla_Extranjera.Balla_Extranjera'"));

	MallaArmas = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	MallaArmas->SetMaterial(0, MaterialArma.Object);
	MallaArmas->SetStaticMesh(Mesh.Object);

    FireRate = 3.0f;//Cadencia Balas
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
void AComponenteArmas::BeginPlay()
{
	Super::BeginPlay();
	
    GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AComponenteArmas::FireProjectile, FireRate, true);
}

// Called every frame
void AComponenteArmas::Tick(float DeltaTime) 
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

void AComponenteArmas::FireProjectile()
{
    AProjectileEnemigo* Projectile = GetWorld()->SpawnActor<AProjectileEnemigo>(AProjectileEnemigo::StaticClass(), GetActorLocation(), GetActorRotation());
    if (Projectile)
    {
        // Obtén la dirección hacia adelante de la nave enemiga
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotación basada en la dirección hacia adelante

        //FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

        FRotator SpawnRotation = ForwardDirection.Rotation();
        
        // Configura la posición y dirección del proyectil
        FVector SpawnLocation = GetActorLocation();
        SpawnLocation.X += 200;
 
        Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

        // Dispara el proyectil
        Projectile->Fire();
    }
}

void AComponenteArmas::RecibirDanio()
{
    vida--;
    if (vida <= 0)
    {
		Destroy();
	}
}


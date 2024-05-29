// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmaAmiga.h"
#include "RadarEnemigo.h"
#include "NaveEnemigaCaza.h"
#include "ProjectileEnemigo.h"

// Sets default values
AArmaAmiga::AArmaAmiga()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/NaveEnemiga.NaveEnemiga'"));
    static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialArma(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/BlueMaterial.BlueMaterial'"));

    MallaArmas = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    MallaArmas->SetMaterial(0, MaterialArma.Object);
    MallaArmas->SetStaticMesh(Mesh.Object);

    FireRate = 3.0f;//Cadencia Balas
}


// Called when the game starts or when spawned
void AArmaAmiga::BeginPlay()
{
    Super::BeginPlay();
    Radar = Cast <ARadarEnemigo>(GetWorld()->SpawnActor(ARadarEnemigo::StaticClass()));
    //Spawnea la bala
    GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AArmaAmiga::FireProjectile, FireRate, true);

}

// Called every frame
void AArmaAmiga::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);




    // Actualizar la posición del arma y notificar al radar si ha cambiado
    FVector NuevaPosicion = GetActorLocation();

    if (NuevaPosicion != PosicionActual)
    {
        PosicionActual = NuevaPosicion;
        NotificarRadar();
        Radar->VerificarNavesEnemigas(PosicionActual);
    }

}

void AArmaAmiga::FireProjectile()
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

void AArmaAmiga::NotificarRadar()
{
    if (Radar)
    {
        Radar->Actualizar(PosicionActual);
    }
}




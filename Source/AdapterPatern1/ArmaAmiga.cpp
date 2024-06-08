// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmaAmiga.h"
#include "RadarEnemigo.h"
#include "NaveEnemigaCaza.h"
#include "ProjectileEnemigo.h"
#include "EstrategiaAtaqueSierra.h"
#include "EstrategiaArmaEscudo.h"
#include "EstrategiaAtaqueNormal.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "IEstrategiasAtaquesPawn.h"

// Sets default values
AArmaAmiga::AArmaAmiga()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/Cube.Cube'"));
   /* static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialArma(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/BlueMaterial.BlueMaterial'"));*/

    MallaArmas = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    /*MallaArmas->SetMaterial(0, MaterialArma.Object);*/
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
    //Spawneamos las estrategias
    EstrategiaEscudo = Cast<AEstrategiaArmaEscudo>(GetWorld()->SpawnActor(AEstrategiaArmaEscudo::StaticClass()));
    EstrategiaSierra = Cast<AEstrategiaAtaqueSierra>(GetWorld()->SpawnActor(AEstrategiaAtaqueSierra::StaticClass()));
    EstrategiaNormal = Cast<AEstrategiaAtaqueNormal>(GetWorld()->SpawnActor(AEstrategiaAtaqueNormal::StaticClass()));
    SetEstrategia(EstrategiaNormal);

}

// Called every frame
void AArmaAmiga::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (Estrategia)
    {
        Estrategia->MoverArma(this, DeltaTime);
        Estrategia->Disparar(this);
    }




    // Actualizar la posici�n del arma y notificar al radar si ha cambiado
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
        // Obt�n la direcci�n hacia adelante de la nave enemiga
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotaci�n basada en la direcci�n hacia adelante

        //FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

        FRotator SpawnRotation = ForwardDirection.Rotation();

        // Configura la posici�n y direcci�n del proyectil
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

void AArmaAmiga::SetEstrategia(AActor* EstrategiaActual)
{
    Estrategia = Cast<IIEstrategiasAtaquesPawn>(EstrategiaActual);
    if (!Estrategia)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("La estrategia no es v�lida"));
    }
}

void AArmaAmiga::CambiarEstrategia(int32 NumeroEstrategia)
{
    if (NumeroEstrategia == 1)
    {
		SetEstrategia(EstrategiaEscudo);
	}
    if (NumeroEstrategia == 2)
    {
		SetEstrategia(EstrategiaSierra);
	}
    if (NumeroEstrategia == 3)
    {
		SetEstrategia(EstrategiaNormal);
	}

}

void AArmaAmiga::CambiarMalla(UStaticMesh* MallaNueva)
{
    if (MallaNueva)
    {
        MallaArmas->SetStaticMesh(MallaNueva);

    }
}




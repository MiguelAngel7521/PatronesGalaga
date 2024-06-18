// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaCapsulas.h"
#include "CapsulaEnergia.h"
#include "CapsulaVida.h"
#include "CapsulaVelocidad.h"

// Sets default values
AFabricaCapsulas::AFabricaCapsulas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaCapsulas::BeginPlay()
{
	Super::BeginPlay();
    // Establece el rango de ubicaciones de spawn
    RangoSpawnX = 500.0f; // Ajusta esto según tu rango deseado en el eje X
    RangoSpawnY = 1000.0f; // Ajusta esto según tu rango deseado en el eje Y

    // Inicia el temporizador para generar cápsulas
    GetWorldTimerManager().SetTimer(TimerHandle, this, &AFabricaCapsulas::GenerarCapsula, 25.0f, true);
}

// Called every frame
void AFabricaCapsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFabricaCapsulas::GenerarCapsula()
{
    FVector SpawnLocation = GetRandomSpawnLocation();
    FRotator SpawnRotation = FRotator::ZeroRotator;
    FActorSpawnParameters SpawnParams;  

    // Elige un tipo de cápsula al azar
    TSubclassOf<ACapsula> ClasCapsulaaGenerar = ObtenerClaseCapsula();

    if (ClasCapsulaaGenerar)
    {
        ACapsula* NuevaCapsulasulaCricion = GetWorld()->SpawnActor<ACapsula>(ClasCapsulaaGenerar, SpawnLocation, SpawnRotation, SpawnParams);

        if (NuevaCapsulasulaCricion)
        {
            // Establece el tiempo de vida de la cápsula a 10 segundos
            GetWorldTimerManager().SetTimer(NuevaCapsulasulaCricion->TimerHandle, NuevaCapsulasulaCricion, &ACapsula::DestruirCapsula, 5.0f, false);
        }
    }
}

FVector AFabricaCapsulas::GetRandomSpawnLocation()
{
    float RandX = FMath::RandRange(-RangoSpawnX, RangoSpawnX);
    float RandY = FMath::RandRange(-RangoSpawnY, RangoSpawnY);
    FVector SpawnLocation = GetActorLocation() + FVector(RandX, RandY, 200.0f); // Ajusta la altura de spawn según sea necesario

    return SpawnLocation;
}

TSubclassOf<ACapsula> AFabricaCapsulas::ObtenerClaseCapsula()
{
    int32 TipoCapsulacion = FMath::RandRange(0, 2);

    switch (TipoCapsulacion)
    {
    case 0:
        return ACapsulaEnergia::StaticClass();
    case 1:
        return ACapsulaVida::StaticClass();
    case 2:
        return ACapsulaVelocidad::StaticClass();
    default:
        return nullptr;
    }
}


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
    RangoSpawnX = 300.0f; // Ajusta esto según tu rango deseado en el eje X
    RangoSpawnY = 1000.0f; // Ajusta esto según tu rango deseado en el eje Y

    // Inicia el temporizador para generar cápsulas
   /* GetWorldTimerManager().SetTimer(TimerHandle, this, &AFabricaCapsulas::GenerarCapsula, 6.0f, true);*/
}

// Called every frame
void AFabricaCapsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFabricaCapsulas::GenerarCapsula(APawn* Pawn, TSubclassOf<ACapsula> CapsulaClass)
{
     FVector SpawnLocation = GetRandomSpawnLocation(Pawn);
    FRotator SpawnRotation = FRotator::ZeroRotator;
    FActorSpawnParameters SpawnParams;

    if (CapsulaClass)
    {
        ACapsula* NuevaCapsula = GetWorld()->SpawnActor<ACapsula>(CapsulaClass, SpawnLocation, SpawnRotation, SpawnParams);

        if (NuevaCapsula)
        {
            // Establece el tiempo de vida de la cápsula a 5 segundos
            GetWorldTimerManager().SetTimer(NuevaCapsula->TimerHandle, NuevaCapsula, &ACapsula::DestruirCapsula, 2.0f, false);
        }
    }
}

FVector AFabricaCapsulas::GetRandomSpawnLocation(APawn* Pawn)
{
    FVector PawnLocation = Pawn->GetActorLocation();
    float RandX = FMath::RandRange(-RangoSpawnX, RangoSpawnX);
    float RandY = FMath::RandRange(-RangoSpawnY, RangoSpawnY);
    FVector SpawnLocation = PawnLocation + FVector(RandX, RandY, 0.0f); // Ajusta la altura de spawn según sea necesario

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


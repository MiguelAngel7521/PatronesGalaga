// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaObstaculos.h"

// Sets default values
AFabricaObstaculos::AFabricaObstaculos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFabricaObstaculos::GenerarObstaculos(int32 CantidadObstaculos, FVector MinSpawnLocation, FVector MaxSpawnLocation, float MinMoveSpeed, float MaxMoveSpeed)
{
    if (GetWorld())
    {
        for (int32 i = 0; i < CantidadObstaculos; ++i)
        {
            FVector SpawnLocation = GetRandomSpawnLocation(MinSpawnLocation, MaxSpawnLocation);
            float MoveSpeed = GetRandomMoveSpeed(MinMoveSpeed, MaxMoveSpeed);
           AObstaculo* Obstaculo = GetWorld()->SpawnActor<AObstaculo>(SpawnLocation, FRotator::ZeroRotator);
            if (Obstaculo)
            {
               /* Obstaculo->SetMoveSpeed(MoveSpeed);*/
                Obstaculos.Add(Obstaculo);
            }
        }
    }
}

// Called when the game starts or when spawned
void AFabricaObstaculos::BeginPlay()
{
	Super::BeginPlay();
   
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFabricaObstaculos::DestroyObstaculos, 15.0f, false);
}

// Called every frame
void AFabricaObstaculos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}



FVector AFabricaObstaculos::GetRandomSpawnLocation(FVector MinSpawnLocation, FVector MaxSpawnLocation)
{
    float X = FMath::RandRange(MinSpawnLocation.X, MaxSpawnLocation.X);
    float Y = FMath::RandRange(MinSpawnLocation.Y, MaxSpawnLocation.Y);
    float Z = 200; // Spawn desde el suelo
    return FVector(X, Y, Z);
}

float AFabricaObstaculos::GetRandomMoveSpeed(float MinMoveSpeed, float MaxMoveSpeed)
{
    return FMath::RandRange(MinMoveSpeed, MaxMoveSpeed);
}

void AFabricaObstaculos::DestroyObstaculos()
{
    for (AObstaculo* Obstaculo : Obstaculos)
    {
        if (Obstaculo)
        {
			Obstaculo->Destroy();
		}
	}
	Obstaculos.Empty();
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaAtaqueFinal.h"
#include "AdapterPatern1Pawn.h"
#include "AdapterPatern1Projectile.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AEstrategiaAtaqueFinal::AEstrategiaAtaqueFinal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    GunOffset = FVector(90.f, 0.f, 0.f);
    bCanFire = true;
    FireRate = 0.1f;
}

// Called when the game starts or when spawned
void AEstrategiaAtaqueFinal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaAtaqueFinal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaAtaqueFinal::EjecutarEstrategia()
{
    Pawn = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
    if (!Pawn) return; // Ensure we have a valid player pawn

    // Calculate a common destination point for all projectiles
    const FVector FireDirection = Pawn->GetActorForwardVector();
    const FVector DestinationPoint = Pawn->GetActorLocation() + FireDirection ; // Adjust MaxDistance as needed

    // If it's ok to fire again
    if (Pawn->EnergiaRestante > 0)
    {
        if (bCanFire == true)
        {
            // Spawn the main projectile at the common destination point
            UWorld* const World = GetWorld();
            if (World != nullptr)
            {
                // Adjust energy consumption
                const int32 EnergyConsumptionPerShot = 2; // Adjust as needed
                Pawn->EnergiaRestante -= EnergyConsumptionPerShot;

                // Adjust fire rate to make it seem like a laser
                const float LaserFireRate = 0.05f; // Adjust as needed
                World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategiaAtaqueFinal::ShotTimerExpired, LaserFireRate);

                // Set bCanFire to false after firing
                bCanFire = false;

                // Spawn the main projectile at the common destination point
                FVector SpawnLocation = DestinationPoint;
                SpawnLocation.X += 200.0f; // Adjust as needed
                const FRotator FireRotation = FireDirection.Rotation();
                World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation, FireRotation);

                // Spawn additional projectiles for laser effect
                const int32 NumAdditionalProjectiles = 5; // Adjust as needed
                for (int32 i = 1; i <= NumAdditionalProjectiles; ++i)
                {
                    const FRotator OffsetRotation = FRotator(0.0f, 360.0f * (float)i / (float)NumAdditionalProjectiles, 0.0f);
                    const FRotator FinalRotation = FireRotation + OffsetRotation;
                    SpawnLocation = DestinationPoint + FinalRotation.Vector() ; // Adjust MaxDistance as needed
                    World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation, FinalRotation);
                }
            }
        }
    }
}

void AEstrategiaAtaqueFinal::ShotTimerExpired()
{
    bCanFire = true;
}


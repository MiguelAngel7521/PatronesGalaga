// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaExplosiva.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "AdapterPatern1Pawn.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include <Kismet/GameplayStatics.h>
#include "AdapterPatern1Projectile.h"


// Sets default values
AEstrategiaExplosiva::AEstrategiaExplosiva()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GunOffset = FVector(90.f, 0.f, 0.f);
	bCanFire = true;
	FireRate = 0.1f;

}

// Called when the game starts or when spawned
void AEstrategiaExplosiva::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaExplosiva::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaExplosiva::Disparar()
{
	Pawn = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	

	FVector FireDirection = Pawn->GetActorForwardVector();
	// If it's ok to fire again
	if (Pawn->EnergiaRestante > 0)
	{
		if (bCanFire == true)
		{
			// If we are pressing fire stick in a direction
			if (FireDirection.SizeSquared() > 0.0f)
			{
				const FRotator FireRotation = FireDirection.Rotation();
				// Spawn projectile at an offset from this pawn
				const FVector SpawnLocation = Pawn->GetActorLocation() + FireRotation.RotateVector(GunOffset);

				UWorld* const World = GetWorld();
				if (World != nullptr)
				{
					// spawn the projectile
					World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation, FireRotation);

					const FRotator FireRotation2 = FireDirection.Rotation() + FRotator(1.0f, 10.0f, 0.0f);
					const FRotator FireRotation3 = FireDirection.Rotation() + FRotator(1.0f, -10.0f, 0.0f);
					const FVector SpawnLocation2 = Pawn->GetActorLocation() + FVector(10.0f, 20.0f, 0.0f) + FireRotation2.RotateVector(GunOffset);
					const FVector SpawnLocation3 = Pawn->GetActorLocation() + FVector(10.0f, -20.0f, 0.0f) + FireRotation3.RotateVector(GunOffset);
					World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation2, FireRotation2);
					World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation3, FireRotation3);

				}

				bCanFire = false;
				World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategiaExplosiva::ShotTimerExpired, FireRate);
				 Pawn->EnergiaRestante -= 5;
				 FString Message2 = FString::Printf(TEXT("Energia restante: %d "), Pawn->ObtenerEnergiaRestante());
				 GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, Message2);

				bCanFire = false;
			}
		}
	}


	// Lógica adicional como efectos visuales o de sonido

}

void AEstrategiaExplosiva::ShotTimerExpired()
{
	bCanFire = true;
}


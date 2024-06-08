// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaArmaEscudo.h"
#include "ArmaAmiga.h"
#include "AdapterPatern1Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "NaveEnemiga.h"
#include "Engine/StaticMesh.h"
#include "AdapterPatern1Projectile.h"

// Sets default values
AEstrategiaArmaEscudo::AEstrategiaArmaEscudo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bRegresando = false;
	bCanFire = true;

}

// Called when the game starts or when spawned
void AEstrategiaArmaEscudo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaArmaEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaArmaEscudo::Disparar(AArmaAmiga* Arma)
{
    if (Arma)
    {
        if (bCanFire)
        {
            FVector SpawnLocation = Arma->GetActorLocation();
            FRotator FireRotation = Arma->GetActorRotation();

           /* GetWorld()->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation + FVector(100.0f, 70.0f, 0.0f), FireRotation);
            GetWorld()->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation + FVector(100.0f, -70.0f, 0.0f), FireRotation);*/

            GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategiaArmaEscudo::ShotTimerExpired, 1.0f);

            // Evitar disparar repetidamente
            bCanFire = false;
            //Cambio de malla
            UStaticMesh* NuevaMalla1 = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Geometry/Meshes/Cylinder.Cylinder'"));

            Arma->CambiarMalla(NuevaMalla1);

            //// Cambiar la escala de la malla
            FVector NuevaEscala = FVector(Arma->GetActorScale().X, 3.0f, 3.0f); // Escala en Y y Z
            Arma->SetActorScale3D(NuevaEscala);
        }
    }
}

void AEstrategiaArmaEscudo::MoverArma(AArmaAmiga* Arma, float DeltaTime)
{
    if (Arma)
    {
        AAdapterPatern1Pawn* Jugador = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
        if (Jugador)
        {
            FVector PosicionJugador = Jugador->GetActorLocation();
            FVector PosicionActual = Arma->GetActorLocation();
            FVector PosicionObjetivo = FVector(PosicionJugador.X + 150.f, PosicionJugador.Y, PosicionJugador.Z);

            FVector NuevaPosicion = FMath::VInterpTo(Arma->GetActorLocation(), PosicionObjetivo, DeltaTime, 2.0f);
            Arma->SetActorLocation(NuevaPosicion);
           /* Arma->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));*/
        }
    }
}

void AEstrategiaArmaEscudo::ShotTimerExpired()
{
	bCanFire = true;
}


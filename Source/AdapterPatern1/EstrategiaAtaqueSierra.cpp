// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaAtaqueSierra.h"
#include "ArmaAmiga.h"
#include "AdapterPatern1Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "NaveEnemiga.h"

// Sets default values
AEstrategiaAtaqueSierra::AEstrategiaAtaqueSierra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaAtaqueSierra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaAtaqueSierra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaAtaqueSierra::Disparar(AArmaAmiga* Arma)
{
    if ( Arma)
    {
        // Ataque Explosivo
        TArray<AActor*> EnemigosCercanos;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANaveEnemiga::StaticClass(), EnemigosCercanos);

        for (AActor* Enemigo : EnemigosCercanos)
        {
            if (Enemigo->GetDistanceTo(Arma) <= 70.0f)
            {
                Enemigo->Destroy();
            }
        }

        // Cambio de malla

        UStaticMesh* NuevaMalla1 = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Geometry/Meshes/TemplateFloor.TemplateFloor'"));
        Arma->CambiarMalla(NuevaMalla1);
    }
}

void AEstrategiaAtaqueSierra::MoverArma(AArmaAmiga* Arma, float DeltaTime)
{
    if (Arma)
    {
        Jugador = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
        FVector PosicionActual = Arma->GetActorLocation();
        if (Jugador)
        {
            // Radio de la circunferencia alrededor de la nave
            float Radio = 450.0f;

            // Incrementa el ángulo con el tiempo
            static float Angulo = 0.0f;
            Angulo += DeltaTime * 3.0f; // Ajustar la velocidad de rotación cambiando este valor

            // Calcula la nueva posición del arma
            FVector PosicionNave = Jugador->GetActorLocation();
            FVector NuevaPosicion = PosicionNave + FVector(FMath::Cos(Angulo) * Radio, FMath::Sin(Angulo) * Radio, 0.0f);

            // Establece la nueva posición del arma
            Arma->SetActorLocation(NuevaPosicion);


        }

    }
}


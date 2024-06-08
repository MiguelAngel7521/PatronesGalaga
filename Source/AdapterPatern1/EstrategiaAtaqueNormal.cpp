// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaAtaqueNormal.h"
#include "ArmaAmiga.h"
#include "AdapterPatern1Projectile.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"


// Sets default values
AEstrategiaAtaqueNormal::AEstrategiaAtaqueNormal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaAtaqueNormal::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEstrategiaAtaqueNormal::ShotTimerExpired()
{
}

// Called every frame
void AEstrategiaAtaqueNormal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaAtaqueNormal::Disparar(AArmaAmiga* Arma)
{
	if (Arma && bCanFire)
	{

		// Obtener la rotación de disparo (hacia adelante a lo largo del eje X)
		const FRotator FireRotation = Arma->GetActorForwardVector().Rotation();
		// Obtener la ubicación de disparo (desde la posición del Pawn con un desplazamiento)
		const FVector SpawnLocation = Arma->GetActorLocation() + FVector(100.0f, 0.0f, 0.0f);
		FVector Distancia = FVector(0.0f, 50.0f, 0.0f);
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// Generar el proyectil
			AAdapterPatern1Projectile* Projectile = World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation, FireRotation);
			AAdapterPatern1Projectile* Projectile1 = World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation - Distancia, FireRotation);
			AAdapterPatern1Projectile* Projectile2 = World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation + Distancia, FireRotation);
			// Establecer el temporizador para el próximo disparo
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategiaAtaqueNormal::ShotTimerExpired, 0.5f);

			// Evitar disparar repetidamente
			bCanFire = false;
		}
		// Cambio de malla

		UStaticMesh* NuevaMalla1 = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
		Arma->CambiarMalla(NuevaMalla1);
	}
}

void AEstrategiaAtaqueNormal::MoverArma(AArmaAmiga* Arma, float DeltaTime)
{
}


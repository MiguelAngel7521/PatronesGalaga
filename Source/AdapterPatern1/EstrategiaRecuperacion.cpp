// Fill out your copyright notice in the Description page of Project Settings.


	#include "EstrategiaRecuperacion.h"
	#include "AdapterPatern1Pawn.h"
	#include <Kismet/GameplayStatics.h>


	// Sets default values
	AEstrategiaRecuperacion::AEstrategiaRecuperacion()
	{
 		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;
		LastRecoveryTime = 0.0f;

	}

	// Called when the game starts or when spawned
	void AEstrategiaRecuperacion::BeginPlay()
	{
		Super::BeginPlay();
	
	}

	// Called every frame
	void AEstrategiaRecuperacion::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		/*EjecutarTiempo();*/

	}

	void AEstrategiaRecuperacion::EjecutarTiempo()
	{
		Pawn = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		FVector PawnVelocity = Pawn->GetVelocity();
		float Speed = PawnVelocity.Size();
	
		if (Speed <= KINDA_SMALL_NUMBER && GetWorld()->TimeSeconds - LastRecoveryTime >= 1.0f)
		{
			Pawn->EnergiaRestante++;
			LastRecoveryTime = GetWorld()->TimeSeconds; // Actualizamos el tiempo de la última recuperación
			FString Message2 = FString::Printf(TEXT("Energia Aumentada: %d "), Pawn->ObtenerEnergiaRestante());
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, Message2);
			if (Pawn->EnergiaRestante > 10000)
			{
				Pawn->EnergiaRestante = 200;
			}
		}
	}	


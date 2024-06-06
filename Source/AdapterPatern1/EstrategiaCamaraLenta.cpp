// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaCamaraLenta.h"
#include "AdapterPatern1Pawn.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AEstrategiaCamaraLenta::AEstrategiaCamaraLenta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaCamaraLenta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaCamaraLenta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaCamaraLenta::EjecutarEstrategia()
{
	Pawn = Cast<AAdapterPatern1Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	UWorld* World = Pawn->GetWorld();
	if (World)
	{
		// Establece la velocidad global del juego a un valor más lento
		World->GetWorldSettings()->SetTimeDilation(0.5f); // Ajusta el valor según sea necesario
	}
}


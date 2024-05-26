// Fill out your copyright notice in the Description page of Project Settings.


#include "Basico.h"
#include "AdapterPatern1Pawn.h"

// Sets default values
ABasico::ABasico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasico::ConArmas()
{
	//Jugador = Cast <AAdapterPatern1Pawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	///*Jugador = GetWorld()->SpawnActor<AAdapterPatern1Pawn>(AAdapterPatern1Pawn::StaticClass());*/
	//if (Jugador->ObtenerEnergiaRestante() > 0)
	//{
	//	//estas en el estado de armas
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("estado Con Armas"));
	//}
}

void ABasico::ConCamuflaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(" Estado Camuflaje No Activado estas en el estado Basico"));
}

void ABasico::ConEscudos()
{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estado ConCamuflaje No Activado estas en el estado Basico"));
}

void ABasico::Invencible()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estado Invencible No Activado estas en el estado Basico"));
}

void ABasico::ConRadar()
{

}


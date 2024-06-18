// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorBuilder.h"

// Sets default values
ADirectorBuilder::ADirectorBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorBuilder::Tick(float DeltaTime)
{ 
	Super::Tick(DeltaTime);

}

void ADirectorBuilder::OrdenarIngeniero(AActor* Ingeniero)
{
	if (!Ingeniero)
	{
		UE_LOG(LogTemp, Error, TEXT("Ingeniero is null!"));
		return;
	}

	IngenieroACargo = Cast<IIngenieroGeneral>(Ingeniero);
	if (!IngenieroACargo)
	{
		UE_LOG(LogTemp, Error, TEXT("Ingeniero does not implement IIngenieroGeneral interface!"));
	}
}

void ADirectorBuilder::ContruirNaveEnemiga(FVector Posicion)
{
	if (IngenieroACargo)
	{
		IngenieroACargo->ConstruirNaveEnUbicacion(Posicion, 1, 1, 1, 0);
	}

}

void ADirectorBuilder::ConstruirNaveEscudo(FVector Posicion)
{
	if (IngenieroACargo)
	{
		IngenieroACargo->ConstruirNaveEnUbicacion(Posicion, 3, 3, 0, 3);
	}
}

void ADirectorBuilder::ConstruirNaveBatalla(FVector Posicion)
{
	if (IngenieroACargo)
	{
		IngenieroACargo->ConstruirNaveEnUbicacion(Posicion, 3, 3, 0, 3);
	}
}

AConstruirNaveEnemiga* ADirectorBuilder::ObtenerNave()
{
	return IngenieroACargo->GetNaveEnemiga();
}


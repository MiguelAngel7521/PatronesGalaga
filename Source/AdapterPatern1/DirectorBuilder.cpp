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
	IngenieroACargo = Cast<IIngenieroGeneral>(Ingeniero);
}

void ADirectorBuilder::ContruirNaveEnemiga()
{
	IngenieroACargo->SetNuevaNave(1);
	IngenieroACargo->SetComponentesArmas(1);
	IngenieroACargo->SetComponentesEscudos(1);
	/*IngenieroACargo->SetComponentesProjectile(1);*/

}

void ADirectorBuilder::ConstruirNaveEscudo()
{
	IngenieroACargo->SetNuevaNave(2);
	IngenieroACargo->SetComponentesArmas(3);
	IngenieroACargo->SetComponentesEscudos(2);
}

void ADirectorBuilder::ConstruirNaveBatalla()
{
	/*IngenieroACargo->SetNuevaNave(3);*/
	IngenieroACargo->SetComponentesArmas(3);
	/*IngenieroACargo->SetComponentesProjectile(3);*/
}

AConstruirNaveEnemiga* ADirectorBuilder::ObtenerNave()
{
	return IngenieroACargo->GetNaveEnemiga();
}


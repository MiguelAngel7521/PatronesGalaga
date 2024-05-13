// Fill out your copyright notice in the Description page of Project Settings.


#include "IngenieroEspecialista2.h"
#include "ConstruirNaveEnemiga.h"

// Sets default values
AIngenieroEspecialista2::AIngenieroEspecialista2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIngenieroEspecialista2::BeginPlay()
{
	Super::BeginPlay();

	ConstruirNave1 = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());

	ConstruirNave1 ->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called every frame
void AIngenieroEspecialista2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIngenieroEspecialista2::SetNuevaNave(int a)
{
	ConstruirNave1->BuildNuevaNave(a);
}

void AIngenieroEspecialista2::SetComponentesArmas(int d)
{
	ConstruirNave1->BuildComponentesArmas(d);
}

void AIngenieroEspecialista2::SetComponentesEscudos(int b)
{
	ConstruirNave1->BuildComponentesEscudos(b);

}

void AIngenieroEspecialista2::SetComponentesProjectile(int c)
{
	ConstruirNave1->BuildComponentesProjectile(c);
}

AConstruirNaveEnemiga* AIngenieroEspecialista2::GetNaveEnemiga()
{
	return ConstruirNave1;
}


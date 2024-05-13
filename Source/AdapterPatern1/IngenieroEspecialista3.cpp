// Fill out your copyright notice in the Description page of Project Settings.


#include "IngenieroEspecialista3.h"
#include "ConstruirNaveEnemiga.h"

// Sets default values
AIngenieroEspecialista3::AIngenieroEspecialista3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIngenieroEspecialista3::BeginPlay()
{
	Super::BeginPlay();
	ConstruirNave2 = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());

	ConstruirNave2 ->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AIngenieroEspecialista3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIngenieroEspecialista3::SetNuevaNave(int a)
{
	ConstruirNave2->BuildNuevaNave(a);
}

void AIngenieroEspecialista3::SetComponentesArmas(int d)
{
	ConstruirNave2->BuildComponentesArmas(d);
}

void AIngenieroEspecialista3::SetComponentesEscudos(int b)
{
	ConstruirNave2->BuildComponentesEscudos(b);
}

void AIngenieroEspecialista3::SetComponentesProjectile(int c)
{
	ConstruirNave2->BuildComponentesProjectile(c);
}

AConstruirNaveEnemiga* AIngenieroEspecialista3::GetNaveEnemiga()
{
	return ConstruirNave2;
}


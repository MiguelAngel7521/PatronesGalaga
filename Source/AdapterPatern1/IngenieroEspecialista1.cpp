// Fill out your copyright notice in the Description page of Project Settings.


#include "IngenieroEspecialista1.h"
#include "ConstruirNaveEnemiga.h"
// Sets default values
AIngenieroEspecialista1::AIngenieroEspecialista1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIngenieroEspecialista1::BeginPlay()
{
	Super::BeginPlay();

	ConstruirNave = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());

	ConstruirNave->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AIngenieroEspecialista1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIngenieroEspecialista1::SetNuevaNave(int a)
{
	ConstruirNave->BuildNuevaNave(a);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Nave Nodriza Implementada"));
}

void AIngenieroEspecialista1::SetComponentesArmas(int d)
{
	ConstruirNave->BuildComponentesArmas(d);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Armas Implementadas"));
}

void AIngenieroEspecialista1::SetComponentesEscudos(int b)
{
	ConstruirNave->BuildComponentesEscudos(b);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Escudos Implementados"));
}

void AIngenieroEspecialista1::SetComponentesProjectile(int c)
{
	ConstruirNave->BuildComponentesProjectile(c);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Proyectiles Implementados"));
}

AConstruirNaveEnemiga* AIngenieroEspecialista1::GetNaveEnemiga()
{
	return ConstruirNave;
}


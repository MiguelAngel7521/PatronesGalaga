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
	ConstruirNave->BuildNuevaNave(FVector::ZeroVector, a);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Nave Enemiga Implementada"));
}

void AIngenieroEspecialista1::SetComponentesArmas(int d)
{

	ConstruirNave->BuildComponentesArmas(FVector::ZeroVector, d);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Armas Implementadas"));
}

void AIngenieroEspecialista1::SetComponentesEscudos(int b)
{
	ConstruirNave->BuildComponentesEscudos(FVector::ZeroVector, b);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Escudos Implementados"));
}

void AIngenieroEspecialista1::SetComponentesProjectile(int c)
{
	ConstruirNave->BuildComponentesProjectile(c);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Proyectiles Implementados"));
}

void AIngenieroEspecialista1::ConstruirNaveEnUbicacion(FVector Posicion, int naveTipo, int armasTipo, int escudosTipo, int proyectilesTipo)
{
	ConstruirNave->ConstruirNaveCompleta(Posicion, naveTipo, armasTipo, escudosTipo, proyectilesTipo);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Nave Compuesta Construida en la Ubicación Especificada"));
}

AConstruirNaveEnemiga* AIngenieroEspecialista1::GetNaveEnemiga()
{
	return ConstruirNave;
}


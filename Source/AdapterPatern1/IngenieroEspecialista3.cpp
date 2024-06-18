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
	ConstruirNave2->BuildNuevaNave(FVector::ZeroVector, a);
}

void AIngenieroEspecialista3::SetComponentesArmas(int d)
{
	ConstruirNave2->BuildComponentesArmas(FVector::ZeroVector, d);
}

void AIngenieroEspecialista3::SetComponentesEscudos(int b)
{
	ConstruirNave2->BuildComponentesEscudos(FVector::ZeroVector, b);
}

void AIngenieroEspecialista3::SetComponentesProjectile(int c)
{
	/*ConstruirNave2->BuildComponentesProjectile(c);*/
}

void AIngenieroEspecialista3::ConstruirNaveEnUbicacion(FVector Posicion, int naveTipo, int armasTipo, int escudosTipo, int proyectilesTipo)
{
	ConstruirNave2->ConstruirNaveCompleta(Posicion, naveTipo, armasTipo, escudosTipo, proyectilesTipo);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Nave Compuesta Construida en la Ubicación Especificada"));
}

AConstruirNaveEnemiga* AIngenieroEspecialista3::GetNaveEnemiga()
{
	return ConstruirNave2;
}


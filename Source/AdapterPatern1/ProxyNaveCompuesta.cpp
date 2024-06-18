// Fill out your copyright notice in the Description page of Project Settings.


#include "ProxyNaveCompuesta.h"
#include "NaveEnemiga.h"
#include "ConstruirNaveEnemiga.h"
#include "EngineUtils.h"

// Sets default values
AProxyNaveCompuesta::AProxyNaveCompuesta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	construirNaveEnemiga = nullptr;
	navesEnemigasRestantes = 0;  // Inicialmente, este valor se debe configurar según la cantidad total de naves enemigas.
}

// Called when the game starts or when spawned
void AProxyNaveCompuesta::BeginPlay()
{
	Super::BeginPlay();
	// Aquí puedes inicializar el contador de naves enemigas restantes.
	for (TActorIterator<ANaveEnemiga> It(GetWorld()); It; ++It)
	{
		navesEnemigasRestantes++;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Naves enemigas restantes: %d"), navesEnemigasRestantes));
	}
}

// Called every frame
void AProxyNaveCompuesta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AProxyNaveCompuesta::BuildNuevaNave(FVector PosicionNave, int z)
{
	// Delega la creación de nuevas naves al builder real
	if (construirNaveEnemiga == nullptr)
	{
		construirNaveEnemiga = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());
	}
	construirNaveEnemiga->BuildNuevaNave(PosicionNave, z);
}

void AProxyNaveCompuesta::BuildComponentesArmas(FVector PosicionBase, int w)
{
	if (construirNaveEnemiga == nullptr)
	{
		construirNaveEnemiga = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());
	}
	construirNaveEnemiga->BuildComponentesArmas(PosicionBase, w);
}

void AProxyNaveCompuesta::BuildComponentesEscudos(FVector PosicionBase, int x)
{
	if (construirNaveEnemiga == nullptr)
	{
		construirNaveEnemiga = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());
	}
	construirNaveEnemiga->BuildComponentesEscudos(PosicionBase, x);
}

void AProxyNaveCompuesta::NaveDestruida()
{
	navesEnemigasRestantes--;

	if (navesEnemigasRestantes <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Todas las naves enemigas han sido destruidas"));
		// Todas las naves han sido destruidas, construir la nave compuesta
		FVector PosicionNaveCompuesta = FVector(1270.0f, 290.0f, 200.0f);
		BuildNuevaNave(PosicionNaveCompuesta, 1);  // Asume que 1 es el código para la nave compuesta
		BuildComponentesArmas(PosicionNaveCompuesta, 3);  // Configura con los componentes deseados
		BuildComponentesEscudos(PosicionNaveCompuesta, 2);  // Configura con los componentes deseados
	}
}


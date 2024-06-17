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
	}
}

// Called every frame
void AProxyNaveCompuesta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProxyNaveCompuesta::BuildNuevaNave(int z)
{
	// Delega la creación de nuevas naves al builder real
	if (construirNaveEnemiga == nullptr)
	{
		construirNaveEnemiga = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());
	}
	construirNaveEnemiga->BuildNuevaNave(z);
}

void AProxyNaveCompuesta::BuildComponentesArmas(int w)
{
	if (construirNaveEnemiga == nullptr)
	{
		construirNaveEnemiga = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());
	}
	construirNaveEnemiga->BuildComponentesArmas(w);
}

void AProxyNaveCompuesta::BuildComponentesEscudos(int x)
{
	if (construirNaveEnemiga == nullptr)
	{
		construirNaveEnemiga = GetWorld()->SpawnActor<AConstruirNaveEnemiga>(AConstruirNaveEnemiga::StaticClass());
	}
	construirNaveEnemiga->BuildComponentesEscudos(x);
}

void AProxyNaveCompuesta::NaveDestruida()
{
	navesEnemigasRestantes--;

	if (navesEnemigasRestantes <= 0)
	{
		// Todas las naves han sido destruidas, construir la nave compuesta
		BuildNuevaNave(1);  // Asume que 1 es el código para la nave compuesta
		BuildComponentesArmas(3);  // Configura con los componentes deseados
		BuildComponentesEscudos(2);  // Configura con los componentes deseados
	}
}


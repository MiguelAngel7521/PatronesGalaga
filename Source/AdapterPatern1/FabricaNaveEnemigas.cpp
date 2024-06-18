// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNaveEnemigas.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaEspia.h"
#include "Engine/World.h"

// Sets default values
AFabricaNaveEnemigas::AFabricaNaveEnemigas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ANaveEnemiga* AFabricaNaveEnemigas::FabricarNave(FString TipoNave, int32 CantidadNaves, int32 NumeroFilas, FVector NNSpawnLocation, UObject* Outer)
{
	TArray<ANaveEnemiga*> Naves;
	TSubclassOf<ANaveEnemiga> NaveClass = ArmarNave(TipoNave);
	UWorld* World = Outer->GetWorld();
	if (NaveClass && World)
	{
		int32 NavesPorFila = 5; // Ajusta esto según el número deseado de naves por fila
		int32 NumeroColumnas = FMath::CeilToInt((float)CantidadNaves / NavesPorFila);
		FRotator rotacion = FRotator(0.0f, 180.0f, 0.0f);
		float EspaciadoX = 400.0f; // Ajusta esto según el espaciado deseado entre filas en el eje X
		float EspaciadoY = 200.0f; // Ajusta esto según el espaciado deseado entre naves en el eje Y

		for (int32 Fila = 0; Fila < NumeroFilas; ++Fila)
		{
			for (int32 Columna = 0; Columna < NavesPorFila; ++Columna)
			{
				int32 Index = Fila * NavesPorFila + Columna;
				if (Index >= CantidadNaves)
				{
					break;
				}

				FVector SpawnLocation = NNSpawnLocation + FVector(Fila * EspaciadoX, Columna * EspaciadoY, 0.0f);
				FActorSpawnParameters SpawnParams;
				ANaveEnemiga* Nave = World->SpawnActor<ANaveEnemiga>(NaveClass, SpawnLocation, rotacion, SpawnParams);
				if (Nave)
				{
					Naves.Add(Nave);
				}
			}
		}
	}
	return Naves.Num() > 0 ? Naves[0] : nullptr;
}

TSubclassOf<ANaveEnemiga> AFabricaNaveEnemigas::ArmarNave(FString TipoNave)
{
    if (TipoNave == "Caza")
    {
        return ANaveEnemigaCaza::StaticClass();
    }
    else if (TipoNave == "Transporte")
    {
        return ANaveEnemigaTransporte::StaticClass();
    }

    else if (TipoNave == "Nodriza")
    {
        return ANaveEnemigaNodriza::StaticClass();
    }
    else if (TipoNave == "Espia")
    {
        return ANaveEnemigaEspia::StaticClass();
    }

    return nullptr;
}

// Called when the game starts or when spawned
void AFabricaNaveEnemigas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaNaveEnemigas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNaveEnemigas.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaEspia.h"

// Sets default values
AFabricaNaveEnemigas::AFabricaNaveEnemigas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ANaveEnemiga* AFabricaNaveEnemigas::FabricarNave(FString TipoNave, UObject* Outer)
{
	TSubclassOf<ANaveEnemiga> NaveClass = ArmarNave(TipoNave);
	if (NaveClass)
	{
		return NewObject<ANaveEnemiga>(Outer, *NaveClass);
	}
	return nullptr;
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


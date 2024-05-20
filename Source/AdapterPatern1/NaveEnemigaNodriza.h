// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()

public:
    ANaveEnemigaNodriza();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
    float Escudos;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
    float AtaqueFinal;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
    float tripulacion;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
    float ataqueEspecial;
protected:
    virtual void BeginPlay() override;

    virtual void Mover(float DeltaTime);




    void DesplegarNavesPequenas();


    void GenerarEscudos();


    void LanzarAtaqueFinal();


    void ReabastecerEnergia();

    void DefenderTripulacion();
};

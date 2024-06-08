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

    virtual void Tick(float DeltaTime) override;




    void DesplegarNavesPequenas();


    void GenerarEscudos();


    void LanzarAtaqueFinal();


    void ReabastecerEnergia();

    void DefenderTripulacion();

    //Patron Observer
    void SuscribirRadar(AActor* Radar);
    void NotificarRadar();

private:
    TArray<AActor*> Observers;

    // Lista de coordenadas de destino
    TArray<FVector> targetLocations;

    // Índice de la ubicación de destino actual
    int32 currentTargetIndex;

    // Velocidad de movimiento de la nave
    float speed = 1000.0f;
};

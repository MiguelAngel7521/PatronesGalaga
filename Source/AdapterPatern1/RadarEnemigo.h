// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Publisher.h"
#include "ISuscriptor.h"
#include "RadarEnemigo.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ARadarEnemigo : public APublisher
{
	GENERATED_BODY()
public:
    ARadarEnemigo();

    void Actualizar(const FVector& PosicionArma);
    virtual void AgregarObservador(IISuscriptor* Suscriptor) override;
    virtual void EliminarObservador(IISuscriptor* Suscriptor) override;
    virtual void Notificar(const FVector& PosicionArma, const FString& Accion) override;
    void VerificarNavesEnemigas();
    FVector UltimaPosicionArma;

private:
    TArray<IISuscriptor*> Suscriptores;
    

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
public:
    FTimerHandle Agrupar;
    FTimerHandle Reabastecer;
    float valorMinimoEnergiaSuscriptor = 10;

    float promedioEnergiaSuscriptores = 0;
    float valorMinimoPromedioEnergia = 30;

    float calcularPromedioEnergiaSuscriptores();

    FVector posicionReabastecimiento;

    float getPromedioEnergiaNavesEnemigas() { return promedioEnergiaSuscriptores; }

};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

public:

    ANaveEnemigaEspia();
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Espia")
    float escudo;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Espia")
    float Sigilo;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Espia")
    float consumo_de_energia;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Espia")
    float Armamento;

protected:


    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;


    virtual void Mover(float DeltaTime);


    void ActivarSigilo();


    void DesactivarSigilo();


    void RecopilarInformacion();


    void InterceptarComunicaciones();

    //Patron Observer
public:
    void SuscribirRadar(AActor* Radar);
    void NotificarRadar();

private:
    TArray<AActor*> Observers;

    

};

// Fill out your copyright notice in the Description page of Project Settings.


// RadarEnemigo.cpp
#include "RadarEnemigo.h"
#include "NaveEnemigaCaza.h"
#include "ISuscriptor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

ARadarEnemigo::ARadarEnemigo()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ARadarEnemigo::BeginPlay()
{
    Super::BeginPlay();
}

void ARadarEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Verificar si alguna nave enemiga necesita evitar el arma
   /* for (ANaveEnemiga* Nave : NavesEnemigas)
    {
        if (Nave->ObtenerEnergia() < 10.0f)
        {
            Notificar("Reabastecer");
        }
        else
        {
            Notificar("EvitarArma");
        } 
    }*/

    // Verificar si alguna nave enemiga necesita reabastecer
   VerificarNavesEnemigas();
}

float ARadarEnemigo::calcularPromedioEnergiaSuscriptores()
{
    float EnergiaTotal = 0.0f;
    int32 NumeroDeSuscriptores = Suscriptores.Num();

    for (IISuscriptor* Suscriptor : Suscriptores)
    {
        if (Suscriptor)
        {
            EnergiaTotal += Suscriptor->ObtenerEnergia();
        }
    }

    promedioEnergiaSuscriptores = (NumeroDeSuscriptores > 0) ? (EnergiaTotal / NumeroDeSuscriptores) : 0.0f;
    return promedioEnergiaSuscriptores;
}

void ARadarEnemigo::Actualizar(const FVector& PosicionArma)
{
    UltimaPosicionArma = PosicionArma;
    /*Notificar(PosicionArma,Accion);*/
}

void ARadarEnemigo::AgregarObservador(IISuscriptor* Suscriptor)
{
    if (Suscriptor)
    {
        Suscriptores.Add(Suscriptor);
    }
}

void ARadarEnemigo::EliminarObservador(IISuscriptor* Suscriptor)
{
    Suscriptores.Remove(Suscriptor);
}

void ARadarEnemigo::Notificar(const FVector& PosicionArma, const FString& Accion)
{
    for (IISuscriptor* Suscriptor : Suscriptores)
    {
        if (Suscriptor)
        {
            Suscriptor->Actualizar(PosicionArma,Accion);
        }
    }
 }

void ARadarEnemigo::VerificarNavesEnemigas()
{
    for (IISuscriptor* Suscriptor : Suscriptores)
    {
        ANaveEnemigaCaza* NaveEnemiga = Cast<ANaveEnemigaCaza>(Suscriptor);
        if (NaveEnemiga)
        {
            if (NaveEnemiga->ObtenerEnergia() < 10.0f)
            {
                Notificar(FVector::ZeroVector, "Reabastecer"); // Notificar la acción de reabastecer
            }
            else
            {
                FVector PosicionNave = NaveEnemiga->GetActorLocation();
                if (FMath::Abs(PosicionNave.Y - UltimaPosicionArma.Y) < 100.0f) // Distancia mínima de seguridad en el eje Y
                {
                    Notificar(FVector::ZeroVector, "Reabastecer"); // Notificar la acción de evitar arma
                }
            }
        }
    }
}


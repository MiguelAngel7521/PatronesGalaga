// Fill out your copyright notice in the Description page of Project Settings.


#include "AtaqueVisitor.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaTransporte.h"
#include "ProjectileEnemigo.h"

// Sets default values
AAtaqueVisitor::AAtaqueVisitor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAtaqueVisitor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAtaqueVisitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAtaqueVisitor::VisitNaveEnemigaCaza(ANaveEnemigaCaza* Nave)
{
    // Obtener todos los proyectiles de la nave y cambiar su tipo de ataque
    TArray<AActor*> Proyectiles;
    Nave->GetAttachedActors(Proyectiles);
    for (AActor* ProyectilActor : Proyectiles)
    {
        AProjectileEnemigo* Proyectil = Cast<AProjectileEnemigo>(ProyectilActor);
        if (Proyectil)
        {
            // Llamar al método correspondiente según el tipo de ataque deseado
            // Por ejemplo, para Ataque Sierra:
            AtaqueSierra(Proyectil);
        }
    }
}

void AAtaqueVisitor::VisitNaveEnemigaEspia(ANaveEnemigaEspia* Nave)
{
    // Obtener todos los proyectiles de la nave y cambiar su tipo de ataque
    TArray<AActor*> Proyectiles;
    Nave->GetAttachedActors(Proyectiles);
    for (AActor* ProyectilActor : Proyectiles)
    {
        AProjectileEnemigo* Proyectil = Cast<AProjectileEnemigo>(ProyectilActor);
        if (Proyectil)
        {
            // Llamar al método correspondiente según el tipo de ataque deseado
            // Por ejemplo, para Ataque Sierra:
            AtaqueSierra(Proyectil);
        }
    }
}

void AAtaqueVisitor::VisitNaveEnemigaNodriza(ANaveEnemigaNodriza* Nave)
{
    // Obtener todos los proyectiles de la nave y cambiar su tipo de ataque
    TArray<AActor*> Proyectiles;
    Nave->GetAttachedActors(Proyectiles);
    for (AActor* ProyectilActor : Proyectiles)
    {
        AProjectileEnemigo* Proyectil = Cast<AProjectileEnemigo>(ProyectilActor);
        if (Proyectil)
        {
            // Llamar al método correspondiente según el tipo de ataque deseado
            // Por ejemplo, para Ataque Sierra:
            AtaqueSierra(Proyectil);
        }
    }
}

void AAtaqueVisitor::VisitNaveEnemigaTransporte(ANaveEnemigaTransporte* Nave)
{
    // Obtener todos los proyectiles de la nave y cambiar su tipo de ataque
    TArray<AActor*> Proyectiles;
    Nave->GetAttachedActors(Proyectiles);
    for (AActor* ProyectilActor : Proyectiles)
    {
        AProjectileEnemigo* Proyectil = Cast<AProjectileEnemigo>(ProyectilActor);
        if (Proyectil)
        {
            // Llamar al método correspondiente según el tipo de ataque deseado
            // Por ejemplo, para Ataque Sierra:
            AtaqueSierra(Proyectil);
        }
    }
}

void AAtaqueVisitor::VisitComponenteEscudo(AComponenteEscudo* Componente)
{
}

void AAtaqueVisitor::VisitComponenteArmas(AComponenteArmas* Componente)
{
}

void AAtaqueVisitor::AtaqueSierra(AProjectileEnemigo* Proyectil)
{
    //Proyectil->OnTickDelegate.AddLambda([Proyectil](float DeltaTime)
    //    {
    //        FRotator NewRotation = Proyectil->GetActorRotation();
    //        NewRotation.Yaw += 360.0f * DeltaTime; // Rotar 360 grados por segundo
    //        Proyectil->SetActorRotation(NewRotation);
    //    });
}

void AAtaqueVisitor::AtaqueBoomerang(AProjectileEnemigo* Proyectil)
{
    //Proyectil->OnTickDelegate.AddLambda([Proyectil](float DeltaTime)
    //    {
    //        FVector Velocity = Proyectil->ProjectileMovement->Velocity;
    //        FVector BoomerangForce = -Velocity.GetSafeNormal() * 100.0f; // Fuerza que atrae el proyectil de vuelta
    //        Proyectil->ProjectileMovement->Velocity += BoomerangForce * DeltaTime;
    //    });
}


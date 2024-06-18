// Fill out your copyright notice in the Description page of Project Settings.
#include "NaveEnemigaCaza.h"
#include "ProjectileEnemigo.h"
#include "Puntaje.h"
#include "AdapterPatern1Projectile.h"
//Patron Facade
#include "SistemaPuntuacionComponente.h"
//Patron Observer
#include "RadarHDU.h"
#include "IObserverRadar.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "RadarEnemigo.h"
//Patron Visitor
#include "INaveEnemigaVisitor.h"
#include "RecuperacionVisitor.h"
#include "MovimientoVisitor.h"
#include "AtaqueVisitor.h"
//Patron Builder
#include "ComponenteArmas.h"
#include "ComponenteEscudo.h"


USistemaPuntuacionComponente* ANaveEnemigaCaza::SharedSistemaPuntuacionComponente = nullptr;
void ANaveEnemigaCaza::BeginPlay()
{
    Super::BeginPlay();
    //cadencia del projectile
    FireCooldown = 0.f;
    // Suscribir el radar
    for (TActorIterator<ARadarHDU> It(GetWorld()); It; ++It)
    {
        SuscribirRadar(*It);
    }
    //Suscribirse al radar Enemigo
    ARadarEnemigo* RadarEnemigo = Cast<ARadarEnemigo>(GetWorld()->SpawnActor(ARadarEnemigo::StaticClass()));
    if (RadarEnemigo)
    {
        RadarEnemigo->AgregarObservador(this);
    }
    ////Patron Builder 

    //if (Armas && Escudo)
    //{
    //    Armas->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
    //    Escudo->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
    //}
    //Patron Visitor
    MovimientoVisitor = Cast<AMovimientoVisitor>(GetWorld()->SpawnActor(AMovimientoVisitor::StaticClass()));
    RecuperacionVisitor = Cast<ARecuperacionVisitor>(GetWorld()->SpawnActor(ARecuperacionVisitor::StaticClass()));
    AtaqueVisitor = Cast<AAtaqueVisitor>(GetWorld()->SpawnActor(AAtaqueVisitor::StaticClass()));
  
}

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
    UE_LOG(LogTemp, Warning, TEXT("AProjectileEnemigo BeginPlay or constructor called"));

    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
    static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NaveEnemiga.NaveEnemiga'"));
    mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
    mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
    mallaNaveEnemiga->BodyInstance.SetCollisionProfileName("NaveEnemiga");
    mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaCaza::OnHit);
    HiperVelocidad = 1500;
    NumeroMisiles = 10;
    RayosLaserActivos = false;
    DanoRayoLaser = 10;
    TiempoEntreRayosLaser = 1;

    //// Inicializar componentes (como actores)
    //Armas = CreateDefaultSubobject<AComponenteArmas>(TEXT("ComponenteArmas"));
    //Escudo = CreateDefaultSubobject<AComponenteEscudo>(TEXT("ComponenteEscudo"));

    //Creacion del Componente de Puntaje
   /* if (SharedSistemaPuntuacionComponente == nullptr)
    {
        SharedSistemaPuntuacionComponente = CreateDefaultSubobject<USistemaPuntuacionComponente>(TEXT("SistemaPuntuacionComponente"));
        UE_LOG(LogTemp, Warning, TEXT("Creando el componente de puntaje"));
    }*/
    nombre = "NaveEnemigaCaza";

    //Tag
    Tags.Add(FName("Radar"));

    bReabasteciendo = false;

}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //Notificar ala radar cada segundo
    NotificarRadar();

    if (FireCooldown > 0.f)
    {
        FireCooldown -= DeltaTime;
    }
    else
    {
        FireCooldown = 0.f;
    }


    
    if (MovimientoVisitor)
    {
        MovimientoVisitor->VisitNaveEnemigaCaza(this);
    }
    if (RecuperacionVisitor)
	{
		RecuperacionVisitor->VisitNaveEnemigaCaza(this);
	}
    if (AtaqueVisitor)
	{
		AtaqueVisitor->VisitNaveEnemigaCaza(this);
	}


}

void ANaveEnemigaCaza::ActivarRayoLaser()
{
    RayosLaserActivos = true;
}

void ANaveEnemigaCaza::DescativarRayoLaser()
{
    RayosLaserActivos = false;
}


void ANaveEnemigaCaza::DispararRayoLaser()
{
    if (RayosLaserActivos)
    {
        //Disparar rayo laser
    }
}

void ANaveEnemigaCaza::DispararMisiles()
{
    if (NumeroMisiles > 0)
    {
        //Disparar misiles
        NumeroMisiles--;
    }
}



void ANaveEnemigaCaza::FireProjectile()
{
    AProjectileEnemigo* Projectile = GetWorld()->SpawnActor<AProjectileEnemigo>(AProjectileEnemigo::StaticClass(), GetActorLocation(), GetActorRotation());
    if (Projectile)
    {
        // Obt�n la direcci�n hacia adelante de la nave enemiga
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotaci�n basada en la direcci�n hacia adelante

        FRotator SpawnRotation = ForwardDirection.Rotation();


        // Configura la posici�n y direcci�n del proyectil
        FVector SpawnLocation = GetActorLocation();
        SpawnLocation.X -= 10;


        Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

        // Dispara el proyectil
        Projectile->Fire();

        // Disminuir la energ�a al disparar
        Energia -= 20.0f;
        if (Energia < 0.0f)
        {
            Energia = 0.0f;
        }

        // Verificar si la energ�a es menor a 10 para iniciar el reabastecimiento
        if (Energia < 10.0f && !bReabasteciendo)
        {
            bReabasteciendo = true;
        }
    }
}



void ANaveEnemigaCaza::SuscribirRadar(AActor* RadarHDU)
{
    if (RadarHDU->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
    {
        Observers.Add(RadarHDU);
        UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *RadarHDU->GetName());
    }
}

void ANaveEnemigaCaza::NotificarRadar()
{
    for (AActor* Observer : Observers)
    {
        IIObserverRadar* ObserverInterface = Cast<IIObserverRadar>(Observer);
        if (ObserverInterface)
        {
            ObserverInterface->UpdatePosition(this);
            UE_LOG(LogTemp, Warning, TEXT("Notificando radar: %s con Actor: %s"), *Observer->GetName(), *this->GetName());
        }
    }
}

void ANaveEnemigaCaza::Actualizar(const FString& Accion)
{
    /*UltimaPosicionArma = PosicionArma;*/

    if (Accion == "EvitarArma")
    {
        EvitarArma();
    }
    else if (Accion == "Reabastecer")
    {
        bReabasteciendo = true;
    }
}






void ANaveEnemigaCaza::Accept(class IINaveEnemigaVisitor* Visitor)
{
  
    Visitor->VisitNaveEnemigaCaza(this);
}





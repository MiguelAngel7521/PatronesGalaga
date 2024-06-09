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

    //Creacion del Componente de Puntaje
   /* if (SharedSistemaPuntuacionComponente == nullptr)
    {
        SharedSistemaPuntuacionComponente = CreateDefaultSubobject<USistemaPuntuacionComponente>(TEXT("SistemaPuntuacionComponente"));
        UE_LOG(LogTemp, Warning, TEXT("Creando el componente de puntaje"));
    }*/
    nombre = "NaveEnemigaCaza";

    //Tag
    Tags.Add(FName("Radar"));

    Energia = 2000.0f;
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
    //Observer
    if (bReabasteciendo)
    {
        DirigirseReabastecimiento();
    }
       
    // Verificar si la energía es menor a 10 para iniciar el reabastecimiento
    if (Energia < 10.0f && !bReabasteciendo)
    {
        bReabasteciendo = true;
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
        // Obtén la dirección hacia adelante de la nave enemiga
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotación basada en la dirección hacia adelante

        FRotator SpawnRotation = ForwardDirection.Rotation();


        // Configura la posición y dirección del proyectil
        FVector SpawnLocation = GetActorLocation();
        SpawnLocation.X -= 10;


        Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

        // Dispara el proyectil
        Projectile->Fire();

        // Disminuir la energía al disparar
        Energia -= 20.0f;
        if (Energia < 0.0f)
        {
            Energia = 0.0f;
        }

        // Verificar si la energía es menor a 10 para iniciar el reabastecimiento
        if (Energia < 10.0f && !bReabasteciendo)
        {
            bReabasteciendo = true;
        }
    }
}


void ANaveEnemigaCaza::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor->IsA(AAdapterPatern1Projectile::StaticClass()))
    {
        AAdapterPatern1Projectile* Projectile = Cast<AAdapterPatern1Projectile>(OtherActor);
        if (Projectile)
        {
            // Destruye el proyectil
            Projectile->Destroy();

            Destroy();

            if (SharedSistemaPuntuacionComponente)
            {
                SharedSistemaPuntuacionComponente->SumarPuntaje(10.0f, nombre);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("SistemaPuntuacionComponente is null!"));
            }
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

float ANaveEnemigaCaza::ObtenerEnergia() const
{
    return Energia;
}



void ANaveEnemigaCaza::DirigirseReabastecimiento()
{
    FVector PosicionActual = GetActorLocation();
    FVector PosicionReabastecimiento = FVector(2480.0f, -2620.0f, 250.0f); // Ajustar la posición de reabastecimiento según sea necesario
    FVector Direccion = (PosicionReabastecimiento - PosicionActual).GetSafeNormal();
    FVector NuevaPosicion = PosicionActual + Direccion * 200.0f * GetWorld()->DeltaTimeSeconds; // Ajustar velocidad según sea necesario
    SetActorLocation(NuevaPosicion);

    // Verificar si ha llegado a la posición de reabastecimiento
    if (FVector::Dist(PosicionActual, PosicionReabastecimiento) < 100.0f) // Ajustar el umbral según sea necesario
    {
        Energia = 100.0f; // Reabastecer energía
        bReabasteciendo = false;
    }
}

void ANaveEnemigaCaza::Accept(class IINaveEnemigaVisitor* Visitor)
{
  
    Visitor->VisitNaveEnemigaCaza(this);
}


void ANaveEnemigaCaza::EvitarArma()
{
   
    FVector PosicionActual = GetActorLocation();
    PosicionActual.Y += 100.0f;

        if (FMath::Abs(PosicionActual.Y - UltimaPosicionArma.Y) < +1000.0f) // Distancia mínima de seguridad
        {
            // Evitar la posición del arma
            FVector NuevaPosicion = PosicionActual;
            NuevaPosicion.Y += (PosicionActual.Y > UltimaPosicionArma.Y) ? 100.0f : -100.0f;
            SetActorLocation(NuevaPosicion);
        }
    
}



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

}

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
    UE_LOG(LogTemp, Warning, TEXT("AProjectileEnemigo BeginPlay or constructor called"));

    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/NaveEnemiga.NaveEnemiga'"));
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

    Energia = 100.0f;
    bReabasteciendo = false;
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    Angulo += Speed * DeltaTime;

    float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

    FVector NewLocation = FVector(GetActorLocation().X, NuevaY, GetActorLocation().Z);
    SetActorLocation(NewLocation);
    //Notificar ala radar cada segundo
    NotificarRadar();
    //Observer Inge
    EvitarArma();
    if (bReabasteciendo)
    {
        DirigirseReabastecimiento();
    }
    if (Energia < 10.0f && !bReabasteciendo)
    {
        bReabasteciendo = true;
    }



    TiempoTranscurrido++;
    if (TiempoTranscurrido > 500)
    {

        /* UWorld* const World = GetWorld();
         if (World != nullptr)
         {
             FVector ubicacionBomba = GetActorLocation() + FVector(0.0f, 100.0f, 0.0f);
             World->SpawnActor<ABomba>(ubicacionBomba, FRotator::ZeroRotator);
         }*/

        TiempoTranscurrido = 0;
    }

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
    else
    {
        EvitarArma();
        // Otras lógicas de movimiento y combate
    }

    // Verificar si la energía es menor a 10 para iniciar el reabastecimiento
    if (Energia < 10.0f && !bReabasteciendo)
    {
        bReabasteciendo = true;
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

void ANaveEnemigaCaza::mover(float DeltaTime)
{

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
        Energia -= 50.0f;
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

void ANaveEnemigaCaza::Actualizar(const FVector& PosicionArma, const FString& Accion)
{
    UltimaPosicionArma = PosicionArma;

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


void ANaveEnemigaCaza::EvitarArma()
{
    FVector PosicionActual = GetActorLocation();
    if (PosicionActual.Y == UltimaPosicionArma.Y)
    {
        PosicionActual.Y += 100.0f;
    }
    //if (FMath::Abs(PosicionActual.Y - UltimaPosicionArma.Y) < +10.0f) // Distancia mínima de seguridad
    //{
    //    // Evitar la posición del arma
    //    FVector NuevaPosicion = PosicionActual;
    //    NuevaPosicion.Y += (PosicionActual.Y > UltimaPosicionArma.Y) ? 100.0f : -100.0f;
    //    SetActorLocation(NuevaPosicion);
    //}
}



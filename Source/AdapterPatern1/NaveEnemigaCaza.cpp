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

    // Crear una instancia del visitante
    ARecuperacionVisitor* Visitor = GetWorld()->SpawnActor<ARecuperacionVisitor>();

    // Aplicar el visitante a esta nave enemiga
    Accept(Visitor);

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
    // Asignar coordenadas de destino
    targetLocations.Add(FVector(-300, 3000, 200));    // Coordenada 1
    targetLocations.Add(FVector(-700, 2000, 200));  // Coordenada 2
    targetLocations.Add(FVector(-510, 1250, 200));  // Coordenada 3
    targetLocations.Add(FVector(-700, 80, 200));  // Coordenada 4
    targetLocations.Add(FVector(-510, -920, 200));  // Coordenada 5
    targetLocations.Add(FVector(-700, -1960, 200));    // Coordenada 6
    targetLocations.Add(FVector(-300, -3200, 200));    // Coordenada 7
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
       
    // Verificar si la energ�a es menor a 10 para iniciar el reabastecimiento
    if (Energia < 10.0f && !bReabasteciendo)
    {
        bReabasteciendo = true;
    }

    FVector PosicionActual12 = GetActorLocation();
    // Calculate the new position based on the current direction and speed
    FVector newLocation = GetActorLocation();
    FVector targetLocation = targetLocations[currentTargetIndex];
    FVector direction = (targetLocation - newLocation).GetSafeNormal();
    float distance = FVector::Distance(targetLocation, newLocation);
    newLocation += direction * speed * DeltaTime;

    SetActorLocation(newLocation);

    // Verificar si la nave ha llegado a la ubicaci�n de destino actual
    if (distance < 10.0f)
    {
        // Mover a la siguiente ubicaci�n de destino
        currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
    }


    //// Crear una instancia del visitante
    //ARecuperacionVisitor* Visitor = GetWorld()->SpawnActor<ARecuperacionVisitor>();

    //// Aplicar el visitante a esta nave enemiga
    //Accept(Visitor);
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
    FVector PosicionReabastecimiento = FVector(2480.0f, -2620.0f, 250.0f); // Ajustar la posici�n de reabastecimiento seg�n sea necesario
    FVector Direccion = (PosicionReabastecimiento - PosicionActual).GetSafeNormal();
    FVector NuevaPosicion = PosicionActual + Direccion * 200.0f * GetWorld()->DeltaTimeSeconds; // Ajustar velocidad seg�n sea necesario
    SetActorLocation(NuevaPosicion);

    // Verificar si ha llegado a la posici�n de reabastecimiento
    if (FVector::Dist(PosicionActual, PosicionReabastecimiento) < 100.0f) // Ajustar el umbral seg�n sea necesario
    {
        Energia = 100.0f; // Reabastecer energ�a
        bReabasteciendo = false;
    }
}

void ANaveEnemigaCaza::Accept(class IINaveEnemigaVisitor* Visitor)
{
   /* Visitor = Cast<IINaveEnemigaVisitor>(Visitor);*/
    Visitor->VisitNaveEnemigaCaza(this);
}


void ANaveEnemigaCaza::EvitarArma()
{
   
    FVector PosicionActual = GetActorLocation();
    PosicionActual.Y += 100.0f;

        if (FMath::Abs(PosicionActual.Y - UltimaPosicionArma.Y) < +1000.0f) // Distancia m�nima de seguridad
        {
            // Evitar la posici�n del arma
            FVector NuevaPosicion = PosicionActual;
            NuevaPosicion.Y += (PosicionActual.Y > UltimaPosicionArma.Y) ? 100.0f : -100.0f;
            SetActorLocation(NuevaPosicion);
        }
    
}



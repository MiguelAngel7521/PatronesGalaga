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
    if (SharedSistemaPuntuacionComponente == nullptr)
    {
        SharedSistemaPuntuacionComponente = CreateDefaultSubobject<USistemaPuntuacionComponente>(TEXT("SistemaPuntuacionComponente"));
        UE_LOG(LogTemp, Warning, TEXT("Creando el componente de puntaje"));
    }
    nombre = "NaveEnemigaCaza";

    //Tag
    Tags.Add(FName("Radar"));
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
    /*FVector PosicionActual = GetActorLocation();
   float NuevaX = FMath::RandRange(0.0f, 0.0f) * DeltaTime;
   float NuevaY = FMath::RandRange(0.0f, 0.0f) * DeltaTime;
   FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

   SetActorLocation(NuevaPosicion);*/

   //FVector PosicionActual = GetActorLocation();

   ////  letra "Z"
   //static const TArray<FVector> Secuencia = {
   //    FVector(100, 400, 200),
   //    FVector(-500, -100, 200),
   //    FVector(-500, 400, 200),
   //    FVector(-500, 400, 200),
   //    FVector(-500, -100, 200),
   //    FVector(100, 400, 200),
   //
   //   
   //};

   //// seguir la secuencia de puntos
   //static int32 Indice = 0;
   //static FVector ObjetivoZ = Secuencia[Indice];
   //static const float Velocidadz = 100.0f;

   //// 
   //FVector Direccion = (ObjetivoZ - PosicionActual).GetSafeNormal();
   //FVector Desplazamiento = Direccion * Velocidadz * DeltaTime;

   //// 
   //if (FVector::Dist(PosicionActual, ObjetivoZ) < 5.0f)
   //{
   //    // siguiente punto de la secuencia
   //    Indice = (Indice + 1) % Secuencia.Num();
   //    ObjetivoZ = Secuencia[Indice];
   //}
   //else
   //{
   //    
   //    SetActorLocation(PosicionActual + Desplazamiento);
   //}
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

void ANaveEnemigaCaza::SuscribirRadar(AActor* Radar)
{
    if (Radar->GetClass()->ImplementsInterface(UIObserverRadar::StaticClass()))
    {
        Observers.Add(Radar);
        UE_LOG(LogTemp, Warning, TEXT("Suscrito al radar: %s"), *Radar->GetName());
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



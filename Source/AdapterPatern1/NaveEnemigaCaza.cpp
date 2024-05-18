// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "ProjectileEnemigo.h"
#include "Puntaje.h"

void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();

 

	FireCooldown = 0.f;
}

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	UE_LOG(LogTemp, Warning, TEXT("AProjectileEnemigo BeginPlay or constructor called"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/NaveEnemiga.NaveEnemiga'"));
    static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NaveEnemiga.NaveEnemiga'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
    mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
	HiperVelocidad = 1500;
	NumeroMisiles = 10;
	RayosLaserActivos = false;
	DanoRayoLaser = 10;
	TiempoEntreRayosLaser = 1;
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    /* Angulo += Speed * DeltaTime;
     float PosicionX = GetActorLocation().X + Radio * FMath::Cos(Angulo);
     float PosicionY = GetActorLocation().Y + Radio * FMath::Sin(Angulo);
     FVector NuevaPosicion = FVector(PosicionX, PosicionY, GetActorLocation().Z);
     SetActorLocation(NuevaPosicion);*/

     // Actualizar el ProjectileMovement 

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
        SpawnLocation.X += 200;
        

        Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

        // Dispara el proyectil
        Projectile->Fire();
    }
}

void ANaveEnemigaCaza::DestruirNaveEnemiga()
{
    APuntaje* puntaje = Cast<APuntaje>(GetWorld()->GetFirstPlayerController()->GetPawn());
    puntaje->CalcularPuntaje(50.0f);
    Destroy();
}

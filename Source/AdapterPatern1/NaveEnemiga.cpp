// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "ProjectileEnemigo.h"
#include "Puntaje.h"
#include "AdapterPatern1Projectile.h"
//Patron Facde
#include "SistemaPuntuacionComponente.h" 
//Patron Observer
#include "RadarHDU.h"
#include "IObserverRadar.h"
#include "Engine/World.h" 
#include "EngineUtils.h"
#include "RadarEnemigo.h"
#include "NaveEnemigaCaza.h"



// Sets default values
USistemaPuntuacionComponente* ANaveEnemiga::SharedSistemaPuntuacionComponente = nullptr;
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	mallaNaveEnemiga->SetCollisionProfileName(TEXT("Pawn"));
	mallaNaveEnemiga->BodyInstance.SetCollisionProfileName(TEXT("Pawn"));
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemiga::OnHit);
	RootComponent = mallaNaveEnemiga;

	Radio = 300.0f; // Radio de la circunferencia
	Angulo = 600.0f; // �ngulo inicial
	Speed = 5.0f;

	/*MovimientoNavesComponent = CreateDefaultSubobject<UAComponenteMovimiento>(TEXT("MovimientoNavesComponente"));*/

	FireRate = 3.0f;//Cadencia Balas

	//Creacion del Componente de Puntaje
	if (SharedSistemaPuntuacionComponente == nullptr)
	{
		SharedSistemaPuntuacionComponente = CreateDefaultSubobject<USistemaPuntuacionComponente>(TEXT("SistemaPuntuacionComponente"));
		UE_LOG(LogTemp, Warning, TEXT("Creando el componente de puntaje"));
	}
	nombre = "NaveEnemiga";
	//Tag
	Tags.Add(FName("Radar"));
	Energia = 100.0f;
	

}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ANaveEnemiga::FireProjectile, FireRate, true);
	// Suscribir el radar
	/*for (TActorIterator<ARadarEnemigo> It(GetWorld()); It; ++It)
	{
		Radar = *It;
		if (Radar)
		{
			Radar->AgregarObservador(this);
			break;
		}
	}*/
	
	
}

void ANaveEnemiga::FireProjectile()
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
		SpawnLocation.X += 200;

		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

		// Dispara el proyectil
		Projectile->Fire();


		
	}
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Angulo += Speed * DeltaTime;

	float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	FVector NewLocation = FVector(GetActorLocation().X, NuevaY, GetActorLocation().Z);
	SetActorLocation(NewLocation);
	//Notificar ala radar cada segundo
	NotificarRadar();

 
}


void ANaveEnemiga::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor->IsA(AAdapterPatern1Projectile::StaticClass()))
	{
		AAdapterPatern1Projectile* Projectile = Cast<AAdapterPatern1Projectile>(OtherActor);
		if (Projectile)
		{
			//// Destruye el proyectil
			//Projectile->Destroy();

			Destroy();

			/*if (SharedSistemaPuntuacionComponente)
			{
				SharedSistemaPuntuacionComponente->SumarPuntaje(10.0f, nombre);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("SistemaPuntuacionComponente is null!"));
			}*/
		}
	}
}



void ANaveEnemiga::NotificarRadar()
{

	
}

void ANaveEnemiga::EvitarArma()
{
	FVector PosicionActual = GetActorLocation();
	PosicionActual.Y += 100.0f; // Ajusta la l�gica para evitar el arma
	SetActorLocation(PosicionActual);	
}

void ANaveEnemiga::DirigirseReabastecimiento()
{
	FVector PuntoReabastecimiento(2480.0f, -2620.0f, 250.0f); // Define la ubicaci�n del punto de reabastecimiento
	SetActorLocation(PuntoReabastecimiento);
}

float ANaveEnemiga::ObtenerEnergia() const
{
	return Energia;
}


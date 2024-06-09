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
	Angulo = 600.0f; // Ángulo inicial
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
	//Suscribirse al radar Enemigo
	ARadarEnemigo* RadarEnemigo = Cast<ARadarEnemigo>(GetWorld()->SpawnActor(ARadarEnemigo::StaticClass()));
	if (RadarEnemigo)
	{
		RadarEnemigo->AgregarObservador(this);
	}
	Energia = 2000.0f;
	bReabasteciendo = false;
	
}

void ANaveEnemiga::FireProjectile()
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

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//Notificar ala radar cada segundo
	NotificarRadar();

	if (bReabasteciendo)
	{
		DirigirseReabastecimiento();
	}
	if (Energia < 10.0f && !bReabasteciendo)
	{
		bReabasteciendo = true;
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
	PosicionActual.Y += 100.0f; // Ajusta la lógica para evitar el arma
	SetActorLocation(PosicionActual);	
}

void ANaveEnemiga::DirigirseReabastecimiento()
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

void ANaveEnemiga::Actualizar(const FString& Accion)
{
	if (Accion == "EvitarArma")
	{
		EvitarArma();
	}
	else if (Accion == "Reabastecer")
	{
		bReabasteciendo = true;
	}
}

float ANaveEnemiga::ObtenerEnergia() const
{
	return Energia;
}

void ANaveEnemiga::RecibirDanio()
{
	Vida -= 1;
	if (Vida <= 0)
	{
		Destroy();
	}
}

void ANaveEnemiga::Accept(IINaveEnemigaVisitor* Visitor)
{
}





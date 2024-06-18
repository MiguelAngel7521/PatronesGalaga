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
//Patron Proxy
#include "ProxyNaveCompuesta.h"


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
	Energia = 200.0f;
	bReabasteciendo = false;
	

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
		SpawnLocation.X -= 10;


		Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

		// Dispara el proyectil
		Projectile->Fire();

		// Disminuir la energía al disparar
		Energia -= 1.0f;
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

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//Notificar ala radar cada segundo
	NotificarRadar();

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

			
		}
	}
}



void ANaveEnemiga::NotificarRadar()
{

	
}

void ANaveEnemiga::EvitarArma()
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
	else
	{
		// Continuar con el movimiento normal
		FVector Direccion = FVector(FMath::Cos(FMath::DegreesToRadians(Angulo)), FMath::Sin(FMath::DegreesToRadians(Angulo)), 0.0f);
		FVector NuevaPosicion = PosicionActual + Direccion * Speed * GetWorld()->DeltaTimeSeconds;
		SetActorLocation(NuevaPosicion);
		Angulo += 1.0f;
		if (Angulo >= 360.0f)
		{
			Angulo = 0.0f;
		}
	}
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
		// Notify the proxy about the destruction
		for (TActorIterator<AProxyNaveCompuesta> It(GetWorld()); It; ++It)
		{
			AProxyNaveCompuesta* Proxy = *It;
			if (Proxy)
			{
				Proxy->NaveDestruida();
				break;
			}
		}
	}
}

void ANaveEnemiga::Accept(IINaveEnemigaVisitor* Visitor)
{
}





// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "ProjectileEnemigo.h"
#include "Puntaje.h"
#include "AdapterPatern1Projectile.h"
//Patron Facde
#include "SistemaPuntuacionComponente.h" 
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
	

}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ANaveEnemiga::FireProjectile, FireRate, true);
	
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

	Angulo += Speed * DeltaTime;

	float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	FVector NewLocation = FVector(GetActorLocation().X, NuevaY, GetActorLocation().Z);
	SetActorLocation(NewLocation);



	//Angulo += Speed * DeltaTime;

	////// Calcula las nuevas posiciones en x y y
	//float NuevaX = GetActorLocation().X + Radio * FMath::Cos(Angulo) * DeltaTime;
	//float NuevaY = GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	////// Establece la nueva posición
	//FVector NewLocation = FVector(NuevaX, NuevaY, GetActorLocation().Z);
	//SetActorLocation(NewLocation);

	//MovimientoNavesComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr); 
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


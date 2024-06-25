// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "AdapterPatern1Projectile.h"

// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Initialize mallaObstaculo
	mallaObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaObstaculo"));
	RootComponent = mallaObstaculo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/Obstaculos.Obstaculos'"));
	if (Mesh.Succeeded())
	{
		mallaObstaculo->SetStaticMesh(Mesh.Object);
		mallaObstaculo->BodyInstance.SetCollisionProfileName("Obstaculo");
		mallaObstaculo->OnComponentHit.AddDynamic(this, &AObstaculo::OnHit);
	}
	Vida = 100.0f;
	Dano = 10.0f;
	bIsMoving = false;
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	MovimientoAparicion();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsMoving)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, 2.0f);

		SetActorLocation(NewLocation);

		if (FVector::Dist(CurrentLocation, TargetLocation) < 1.0f)
		{
			bIsMoving = false;
		}
	}
}

void AObstaculo::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
		AAdapterPatern1Projectile* Proyectil = Cast<AAdapterPatern1Projectile>(OtherActor);
		if (Proyectil)
		{
		
		RecibirDano();
		if (Vida <= 0)
		{
			Destroy();
		}
	}
}

void AObstaculo::RecibirDano()
{
		Vida -= Dano;
}

void AObstaculo::MovimientoAparicion()
{
	TargetLocation = GetActorLocation();
	TargetLocation.Z += 200.0f;
	bIsMoving = true;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteArmas.h"
#include "ProjectileEnemigo.h"
#include "INaveEnemigaVisitor.h"
#include "RecuperacionVisitor.h"
#include "MovimientoVisitor.h"
#include "AtaqueVisitor.h"

// Sets default values
AComponenteArmas::AComponenteArmas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/NaveEnemiga.NaveEnemiga'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialArma(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/Balla_Extranjera.Balla_Extranjera'"));

	MallaArmas = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	MallaArmas->SetMaterial(0, MaterialArma.Object);
	MallaArmas->SetStaticMesh(Mesh.Object);

    FireRate = 3.0f;//Cadencia Balas

}

// Called when the game starts or when spawned
void AComponenteArmas::BeginPlay()
{
	Super::BeginPlay();
	
    GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &AComponenteArmas::FireProjectile, FireRate, true);
    MovimientoVisitor = Cast<AMovimientoVisitor>(GetWorld()->SpawnActor(AMovimientoVisitor::StaticClass()));
    RecuperacionVisitor = Cast<ARecuperacionVisitor>(GetWorld()->SpawnActor(ARecuperacionVisitor::StaticClass()));
    AtaqueVisitor = Cast<AAtaqueVisitor>(GetWorld()->SpawnActor(AAtaqueVisitor::StaticClass()));
}

// Called every frame
void AComponenteArmas::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

    if (MovimientoVisitor)
    {
        MovimientoVisitor->VisitComponenteArmas(this);
    }
    if (RecuperacionVisitor)
    {
        RecuperacionVisitor->VisitComponenteArmas(this);
    }
    if (AtaqueVisitor)
    {
        AtaqueVisitor->VisitComponenteArmas(this);
    }
}

void AComponenteArmas::FireProjectile()
{
    AProjectileEnemigo* Projectile = GetWorld()->SpawnActor<AProjectileEnemigo>(AProjectileEnemigo::StaticClass(), GetActorLocation(), GetActorRotation());
    if (Projectile)
    {
        // Obt�n la direcci�n hacia adelante de la nave enemiga
        FVector ForwardDirection = GetActorForwardVector();

        // Calcula la rotaci�n basada en la direcci�n hacia adelante

        //FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

        FRotator SpawnRotation = ForwardDirection.Rotation();
        
        // Configura la posici�n y direcci�n del proyectil
        FVector SpawnLocation = GetActorLocation();
        SpawnLocation.X += 200;
 
        Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

        // Dispara el proyectil
        Projectile->Fire();
    }
}

void AComponenteArmas::RecibirDanio()
{
    vida--;
    if (vida <= 0)
    {
		Destroy();
	}
}

void AComponenteArmas::Accept(IINaveEnemigaVisitor* Visitor)
{
	Visitor->VisitComponenteArmas(this);
}


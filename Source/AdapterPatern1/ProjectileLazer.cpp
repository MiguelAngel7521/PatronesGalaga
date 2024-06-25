// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileLazer.h"
#include "AdapterPatern1Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ArmaAmiga.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectileLazer::AProjectileLazer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("StaticMesh'/Game/Meshes/Missile.Missile'"));
    lasermalla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
    if (BallMesh.Succeeded())
    {
        lasermalla->SetStaticMesh(BallMesh.Object);
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BallMesh load failed"));
    }

    lasermalla->SetupAttachment(RootComponent);
    RootComponent = lasermalla;
    lasermalla->BodyInstance.SetCollisionProfileName("Projectile");
    lasermalla->OnComponentHit.AddDynamic(this, &AProjectileLazer::OnHit);

    lasermalla->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    lasermalla->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
    lasermalla->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    lasermalla->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AProjectileLazer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileLazer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	varTick += GetWorld()->GetDeltaSeconds();
	if (varTick >= 1.5f)
	{
		FVector esti = GetActorScale3D();
		esti.X += potenc * DeltaTime;
		SetActorRelativeScale3D(esti);
	}
	if (varTick >= 2.5) {
		Destroy();
	}

}

void AProjectileLazer::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("OnHit triggered"));

    AAdapterPatern1Pawn* Pawn = Cast<AAdapterPatern1Pawn>(OtherActor);
    if (Pawn)
    {
        Pawn->VidasRestantes -= 5;
        FString Message = FString::Printf(TEXT("Vidas restantes: %d "), Pawn->GetVidasRestantes());
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message);
        FString Message2 = FString::Printf(TEXT("Energia restante: %d "), Pawn->ObtenerEnergiaRestante());
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, Message2);
    }

    if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
    {
        OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
    }

    if (OtherActor != nullptr && OtherActor != this)
    {
        AArmaAmiga* Arma = Cast<AArmaAmiga>(OtherActor);
        if (Arma)
        {
            Arma->RecibirDano();
        }
    }

    Destroy();
}




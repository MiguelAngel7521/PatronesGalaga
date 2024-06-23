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
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("StaticMesh'/Game/Meshes/BulletLevel2.BulletLevel2'"));
	lasermalla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh'/Game/Meshes/BulletLevel2.BulletLevel2'"));
	RootComponent = lasermalla;
	SetActorScale3D(FVector(1, 5, 1));
	lasermalla->SetStaticMesh(BallMesh.Object);
	//lasermalla->SetupAttachment(RootComponent);//asigna el objeto mallaProyectil al componente raiz
	//RootComponent = lasermalla;
	//lasermalla->BodyInstance.SetCollisionProfileName("Projectile");
	//lasermalla->OnComponentHit.AddDynamic(this, &AProjectileLazer::OnHit);

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
	
}




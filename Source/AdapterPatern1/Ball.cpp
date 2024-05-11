// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
//#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
//#include "TwoBall.h"
//#include "ThreeBall.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/BallExtranjera.BallExtranjera'"));
	//Segunda forma de crear material
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/Balla_Extranjera.Balla_Extranjera'"));
	//Primera forma de crear material
	//static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/BallMaterial.BallMaterial'"));
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	SM_Ball->SetMaterial(0, MaterialBall.Object);
	//SM_Ball->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XYPlane);
	SM_Ball->SetStaticMesh(BallMesh.Object);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetRootComponent(SM_Ball);

	CollisionBall = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Box Collision Ball"));
	CollisionBall->SetCapsuleRadius(5.0f);
	CollisionBall->SetCapsuleHalfHeight(5.0f);
	CollisionBall->SetupAttachment(GetRootComponent());

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 0.0f;
	ProjectileMovement->MaxSpeed = 600.0f;
	ProjectileMovement->bRotationFollowsVelocity = true; //La rotacion sigue la velocidad
	ProjectileMovement->bInitialVelocityInLocalSpace = true; //Velocidad inicial en espacio local
	ProjectileMovement->bShouldBounce = false; //Debe rebotar
	ProjectileMovement->Bounciness = 1.0f; //Rebote
	ProjectileMovement->Friction = 0.5f; //Friccion
	ProjectileMovement->BounceVelocityStopSimulatingThreshold = 10.0f; //Umbral de velocidad de parada de rebote
	ProjectileMovement->bSimulationEnabled = true; //Simulacion activada
	ProjectileMovement->bSweepCollision = true;
	ProjectileMovement->MaxSimulationTimeStep = 0.05;
	ProjectileMovement->MaxSimulationIterations = 12;
	ProjectileMovement->bInterpMovement = true;
	ProjectileMovement->bInterpRotation = true;
	ProjectileMovement->bConstrainToPlane = true;
	ProjectileMovement->ConstrainNormalToPlane(FVector(0.0f, 1.0f, 0.0f));
	ProjectileMovement->Velocity = FVector(1.0f, 0.0f, 1.0f);
	ProjectileMovement->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Custom);
	bCanCollide = true;
}

void ABall::Launch()
{
	if (!BallLaunched) 
	{
		SM_Ball->AddImpulse(FVector(200.0f, 900.0f, 0.0f), FName(), true);
		BallLaunched = true;
		
	}
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

void ABall::DestroyBall()
{
	Destroy();
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	CollisionBall->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlapBegin);
}



void ABall::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (bCanCollide)
	//{
		// Realizar la lógica de colisión
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Choco")));
		FVector NewVelocity = CalculateReflectionVelocity(ProjectileMovement->Velocity, SweepResult.ImpactNormal);
		ProjectileMovement->Velocity = NewVelocity;

		// Desactivar la capacidad de colisión temporalmente
		//bCanCollide = false;
		FTimerHandle UnusedHandle;
		// Configurar un temporizador para volver a activar la capacidad de colisión después de un cierto tiempo
		//GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &ABall::EnableCollision, 1.0f, false);
	//}
}

FVector ABall::CalculateReflectionVelocity(const FVector& CurrentVelocity, const FVector& SurfaceNormal)
{
	return CurrentVelocity - 2 * FVector::DotProduct(CurrentVelocity, SurfaceNormal) * SurfaceNormal;;
}

void ABall::SetVelocity(const FVector& NewVelocity)
{
	UPrimitiveComponent* BallPrimitive = Cast<UPrimitiveComponent>(RootComponent);
	if (BallPrimitive)
	{
		BallPrimitive->SetPhysicsLinearVelocity(NewVelocity, true);
	}
}

void ABall::EnableCollision()
{
	bCanCollide = true;
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//ProjectileMovement->Velocity = FVector(200.0f, 0.0f, 300.0f);

}



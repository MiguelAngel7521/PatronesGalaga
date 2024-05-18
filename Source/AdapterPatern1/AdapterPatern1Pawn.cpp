// Copyright Epic Games, Inc. All Rights Reserved
#include "AdapterPatern1Pawn.h"
#include "AdapterPatern1Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "CapsulasFacade.h"
//#include "Bomba.h"

const FName AAdapterPatern1Pawn::MoveForwardBinding("MoveForward");
const FName AAdapterPatern1Pawn::MoveRightBinding("MoveRight");
const FName AAdapterPatern1Pawn::FireForwardBinding("FireForward");
const FName AAdapterPatern1Pawn::FireRightBinding("FireRight");

AAdapterPatern1Pawn::AAdapterPatern1Pawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
}

void AAdapterPatern1Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
}

void AAdapterPatern1Pawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AAdapterPatern1Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AAdapterPatern1Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AAdapterPatern1Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AAdapterPatern1Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AAdapterPatern1Pawn::Lanzar()
{
	BounceBall->Lanzar();
}

void AAdapterPatern1Pawn::SetBounceBall(AActor* _Adaptador)
{
	BounceBall = Cast<IIBounceBall>(_Adaptador);
		if (!BounceBall) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf(TEXT("No se pudo instanciar")));
		}
		return;
}

void AAdapterPatern1Pawn::SpawnBomba()
{
	//if (bBombaSpawned == false) {
	//	if (GetWorld())
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bomba Spawned"));
	//		FVector SpawnLocation = GetActorLocation();
	//		FRotator SpawnRotation = GetActorRotation();

	//		// Utiliza la variable BombaClass para instanciar el objeto ABomba
	//		ABomba* NuevaBomba = GetWorld()->SpawnActor<ABomba>(BombaClass, SpawnLocation, SpawnRotation);
	//		// Spawnea un nuevo actor Bomba en la ubicación del actor actual

	//		if (NuevaBomba)
	//		{
	//			NuevaBomba->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	//			bBombaSpawned = true;
	//		}
	//		else
	//		{
	//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bomba not Spawned"));
	//		}
	//	}
	//}
}

void AAdapterPatern1Pawn::RecibirDanio(int32 CantidadDanio)
{
	ReducirEnergia(CantidadDanio);

	// Si la energía del jugador llega a 0, reducir una vida y reiniciar la energía
	if (EnergiaJugador <= 0)
	{
		VidasJugador--;
		EnergiaJugador = 10; // Reiniciar la energía

		// Verificar si el jugador ha perdido todas sus vidas
		if (VidasJugador <= 0)
		{
			// Aquí puedes manejar la lógica para el fin del juego
			UE_LOG(LogTemp, Warning, TEXT("Juego Terminado"));
		}
	}
}

void AAdapterPatern1Pawn::ReducirEnergia(int32 Cantidad)
{
	EnergiaJugador -= Cantidad;

	// Asegurarse de que la energía no baje de 0
	EnergiaJugador = FMath::Max(0, EnergiaJugador);
}



void AAdapterPatern1Pawn::recibirImpacto()
{
	ContImpacto++;
	if (ContImpacto == 3)
	{
		ContImpacto = 0;
		ReducirVida();
		ReducirEnergia();
	}
}

void AAdapterPatern1Pawn::Energia()
{
	EnergiaJugador++;
	if (EnergiaJugador > 10)
	{
		EnergiaJugador = 10;
	}
}


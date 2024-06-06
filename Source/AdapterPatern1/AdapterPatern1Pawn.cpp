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
//Patron State
#include "Basico.h"
#include "EstadoConArmamentoAdicional.h"
#include "ComponenteEscudo.h"
#include "EstadoConCamuflaje.h"
#include "EstadoConEscudo.h"
#include "EstadoInvencible.h"
#include "IEstados.h"
#include "ArmaAmiga.h"
//Patron Strategy
#include "EstrategiaExplosiva.h"
#include "EstrategiaRecuperacion.h"
#include "EstrategiaCamaraLenta.h"



const FName AAdapterPatern1Pawn::MoveForwardBinding("MoveForward");
const FName AAdapterPatern1Pawn::MoveRightBinding("MoveRight");
const FName AAdapterPatern1Pawn::FireForwardBinding("FireForward");
const FName AAdapterPatern1Pawn::FireRightBinding("FireRight");

AAdapterPatern1Pawn::AAdapterPatern1Pawn()

{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	/*static ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/Pawn.Pawn'"));

	if (Material.Succeeded())
	{
		BaseMaterial = Material.Object;
	}*/
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));		
	RootComponent = ShipMeshComponent;
	/*CamouflageMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CamuflajeMesh"));*/

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

	Escudo = nullptr;
	// Inicializar con el estado básico
	Estado = NewObject<ABasico>();
	Estado->EstablecerJugador(this);

	// Create a dynamic material instance
	/*DynamicMaterialInstance = UMaterialInstanceDynamic::Create(BaseMaterial, this);
	ShipMeshComponent->SetMaterial(0, DynamicMaterialInstance);*/

	//Patron Strategy
	bIsEstrategiaCamaraLentaActive = false;
	bIsEstrategiaRecuperacionActive = false;
	bIsEstrategiaExplosivaActive = false;
	
	
}

void AAdapterPatern1Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	PlayerInputComponent = NewObject<UInputComponent>(this);
	PlayerInputComponent->BindAction("EstrategiaAtaque1", IE_Pressed, this, &AAdapterPatern1Pawn::HandleKey1);
	PlayerInputComponent->BindAction("EstrategiaAtaque2", IE_Pressed, this, &AAdapterPatern1Pawn::HandleKey2);
	PlayerInputComponent->BindAction("EstrategiaAtaque3", IE_Pressed, this, &AAdapterPatern1Pawn::HandleKey3);
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

	if (EstrategiaActual)
	{
		EjecutarEstrategia();
	}
}

void AAdapterPatern1Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (EnergiaRestante > 0)
	{
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
				EnergiaRestante -= 2;
				FString Message2 = FString::Printf(TEXT("Energia restante: %d "), ObtenerEnergiaRestante());
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, Message2);
				bCanFire = false;
			}
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


void AAdapterPatern1Pawn::RecibirDanio(int32 CantidadDanio)
{
	

	// Si la energía del jugador llega a 0, reducir una vida y reiniciar la energía
	if (EnergiaRestante <= -20)
	{
		VidasRestantes--;
		EnergiaRestante = 1000; // Reiniciar la energía

		// Verificar si el jugador ha perdido todas sus vidas
		if (VidasRestantes <= 0)
		{
			// Aquí puedes manejar la lógica para el fin del juego
			UE_LOG(LogTemp, Warning, TEXT("Juego Terminado"));
		}
	}
	
}

void AAdapterPatern1Pawn::ReducirEnergia1()
{
	if (EnergiaRestante > 0)
		EnergiaRestante = EnergiaRestante - 10;
	if (EnergiaRestante < 10)
		MoveSpeed = -600;
	
	if (EnergiaRestante == 50)
	{
		InicializarEstadosJugador("ConEscudos");
		EstadoConEscudos ->ConEscudos();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
	}
	if (EnergiaRestante == 100)
	{
		InicializarEstadosJugador("ConArmamentoAdicional");
		EstadoConArmamentoAdicional->ConArmamentoAdicional();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
	}
	if (EnergiaRestante == 16)
	{
		InicializarEstadosJugador("ConCamuflaje");
		EstadoConCamuflaje->ConCamuflaje();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
	}
	if (EnergiaRestante == 15)
	{
		InicializarEstadosJugador("Invensible");
		EstadoInvensible->Invencible();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
	}
	
		
}

void AAdapterPatern1Pawn::recibirImpacto()
{
	/*ContImpacto++;
	if (ContImpacto == 3)
	{
		ContImpacto = 0;
		ReducirVida();
		ReducirEnergia1();
	}*/
}

void AAdapterPatern1Pawn::ReducirVida()
{
	if (VidasRestantes > 0)
		VidasRestantes--;


	/*if (VidasRestantes == 1) {
		EstrategiaCamaraLenta = GetWorld()->SpawnActor<AEstrategiaCamaraLenta>(AEstrategiaCamaraLenta::StaticClass());
		AlternarEstrategias(EstrategiaCamaraLenta);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Camara Lenta"));
		EstrategiaCamaraLenta->EjecutarEstrategia();


	}

	if (VidasRestantes == 2)
	{

		EstrategiaRecuperacion = GetWorld()->SpawnActor<AEstrategiaRecuperacion>(AEstrategiaRecuperacion::StaticClass());
		AlternarEstrategias(EstrategiaRecuperacion);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Recuperacion"));
		EstrategiaRecuperacion->EjecutarEstrategia();


	}
	if (VidasRestantes == 3)
	{
		EstrategiaExplosiva = GetWorld()->SpawnActor<AEstrategiaExplosiva>(AEstrategiaExplosiva::StaticClass());
		AlternarEstrategias(EstrategiaExplosiva);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Explosiva"));
		EstrategiaExplosiva->EjecutarEstrategia();


	}*/
}

void AAdapterPatern1Pawn::Energia()
{
	EnergiaJugador++;
	if (EnergiaJugador > 10)
	{
		EnergiaJugador = 10;
	}
}

void AAdapterPatern1Pawn::InicializarEstadosJugador(FString _Estados)
{
	// Inicializar con el estado básico
	if (_Estados.Equals("Basico")) {
		EstadoBasico = GetWorld()->SpawnActor<ABasico>(ABasico::StaticClass());
		EstadoBasico->EstablecerJugador(this);
		EstablecerEstados(EstadoBasico);
	}
	if (_Estados.Equals("ConArmamentoAdicional")) {
		EstadoConArmamentoAdicional = GetWorld()->SpawnActor<AEstadoConArmamentoAdicional>(AEstadoConArmamentoAdicional::StaticClass());
		EstadoConArmamentoAdicional->EstablecerJugador(this);
		EstablecerEstados(EstadoConArmamentoAdicional);
	}
	if (_Estados.Equals("Invensible")) {
		EstadoInvensible = GetWorld()->SpawnActor<AEstadoInvencible>(AEstadoInvencible::StaticClass());
		EstadoInvensible->EstablecerJugador(this);
		EstablecerEstados(EstadoInvensible);
	}
	if (_Estados.Equals("ConEscudos")) {
		EstadoConEscudos = GetWorld()->SpawnActor<AEstadoConEscudo>(AEstadoConEscudo::StaticClass());
		EstadoConEscudos->EstablecerJugador(this);
		EstablecerEstados(EstadoConEscudos);
	}
	if (_Estados.Equals("ConCamuflaje")) {
		EstadoConCamuflaje = GetWorld()->SpawnActor<AEstadoConCamuflaje>(AEstadoConCamuflaje::StaticClass());
		EstadoConCamuflaje->EstablecerJugador(this);
		EstablecerEstados(EstadoConCamuflaje);
	}Estado->EstablecerJugador(this);
}


void AAdapterPatern1Pawn::EstablecerEstados(IIEstados* _Estado)
{
	Estado = _Estado;
}

void AAdapterPatern1Pawn::JugadorBasico()
{
	Estado->Basico();
}

void AAdapterPatern1Pawn::JugadorConArmasAdicionales()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 200.0f, 0.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < 2; i++)
		{
			
			ArmaAmiga = GetWorld()->SpawnActor<AArmaAmiga>(AArmaAmiga::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);
			if (ArmaAmiga)
			{
				ArmaAmiga->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			}
			SpawnLocation.Y += -500.0f;
		}

}

void AAdapterPatern1Pawn::JugadorConEscudos()
{
	/*Estado->ConEscudos();*/
	if (!Escudo)
	{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.0f;
			SpawnLocation.X += 100.0f;
			FRotator SpawnRotation = FRotator(0.0f, 90.0f, 0.0f);
			Escudo = GetWorld()->SpawnActor<AComponenteEscudo>(AComponenteEscudo::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);
			if (Escudo)
			{
				Escudo->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			}
	}
}

void AAdapterPatern1Pawn::JugadorInvensible()
{

	//if (DynamicMaterialInstance)
	//{
	//	DynamicMaterialInstance->SetVectorParameterValue("BaseColor", FLinearColor::Yellow); // Cambia "BaseColor" al nombre del parámetro correcto en tu material
	//}
}

void AAdapterPatern1Pawn::JugadorConCamuflaje()
{
	
	
}



IIEstados* AAdapterPatern1Pawn::J_ObtenerEstado()
{
	return Estado;
}

IIEstados* AAdapterPatern1Pawn::J_ObtenerEstadoBasico()
{
	return EstadoBasico;
}

IIEstados* AAdapterPatern1Pawn::J_ObtenerEstadoConArmamentoAdicional()
{
	return EstadoConArmamentoAdicional;
}

IIEstados* AAdapterPatern1Pawn::J_ObtenerEstadoConEscudos()
{
	return EstadoConEscudos;
}

IIEstados* AAdapterPatern1Pawn::J_ObtenerEstadoInvensible()
{
	return EstadoInvensible;
}

IIEstados* AAdapterPatern1Pawn::J_ObtenerEstadoConCamuflaje()
{
	return EstadoConCamuflaje;
}


FString AAdapterPatern1Pawn::J_ObtenerEstadoActual()
{
	if (Estado) {
		return "El estado actual del jugador es: " + Estado->ObtenerEstado();
	}
	else {
		return "Estado no inicializado";
	}
}


void AAdapterPatern1Pawn::AlternarEstrategias(AActor* _EstrategiaPawn)
{
	EstrategiaActual = Cast<IIEstrategia>(_EstrategiaPawn);
	if (!EstrategiaActual)
	{ 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo inicializar EstrategiaActual"));
	}
}

void AAdapterPatern1Pawn::EjecutarEstrategia()
{
	if (EstrategiaActual)
	{
		EstrategiaActual->EjecutarEstrategia();
	}
}

void AAdapterPatern1Pawn::HandleKey1()
{


	//CONTADOR
	if (bIsEstrategiaCamaraLentaActive)
	{
		// Detener la estrategia si ya está activa
		if (EstrategiaCamaraLenta)
		{
			EstrategiaCamaraLenta->Destroy();
			EstrategiaCamaraLenta = nullptr;

		}
		bIsEstrategiaCamaraLentaActive = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Camara Lenta Detenida"));
	}
	else if (VidasRestantes == 1)
	{
		// Activar la estrategia si no está activa
		EstrategiaCamaraLenta = GetWorld()->SpawnActor<AEstrategiaCamaraLenta>(AEstrategiaCamaraLenta::StaticClass());
		if (EstrategiaCamaraLenta)
		{
			EstrategiaCamaraLenta->EjecutarEstrategia();
			bIsEstrategiaCamaraLentaActive = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Camara Lenta Activada"));
		}
	}


}

void AAdapterPatern1Pawn::HandleKey2()
{


	if (VidasRestantes == 2)
	{

		EstrategiaRecuperacion = GetWorld()->SpawnActor<AEstrategiaRecuperacion>(AEstrategiaRecuperacion::StaticClass());
		AlternarEstrategias(EstrategiaRecuperacion);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Recuperacion"));
		EstrategiaRecuperacion->EjecutarEstrategia();
	}
}

void AAdapterPatern1Pawn::HandleKey3()
{
	
	if (VidasRestantes == 3)
	{
		EstrategiaExplosiva = GetWorld()->SpawnActor<AEstrategiaExplosiva>(AEstrategiaExplosiva::StaticClass());
		AlternarEstrategias(EstrategiaExplosiva);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Explosiva"));
		EstrategiaExplosiva->EjecutarEstrategia();


	}
}



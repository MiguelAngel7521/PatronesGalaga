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
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaTransporte.h"
//Patron Strategy
#include "EstrategiaExplosiva.h"
#include "EstrategiaRecuperacion.h"
#include "EstrategiaCamaraLenta.h"
#include "EstrategiaAtaqueFinal.h"
#include "IEstrategiasTiempo.h"
#include "EstrategiaArmaEscudo.h"
#include "EstrategiaAtaqueSierra.h"




const FName AAdapterPatern1Pawn::MoveForwardBinding("MoveForward");
const FName AAdapterPatern1Pawn::MoveRightBinding("MoveRight");
const FName AAdapterPatern1Pawn::FireForwardBinding("FireForward");
const FName AAdapterPatern1Pawn::FireRightBinding("FireRight");

void AAdapterPatern1Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

AAdapterPatern1Pawn::AAdapterPatern1Pawn()

{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> InvencibleMesh2(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_2.TwinStickUFO_2'"));
	if (ShipMesh.Succeeded())
	{
		ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
		ShipMeshComponent->SetWorldScale3D(FVector(1.0f));
		RootComponent = ShipMeshComponent;
		

		
	}
	
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	if (InvencibleMesh2.Succeeded())
	{


		InvencibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_2.TwinStickUFO_2'"));
		// Ensure InvincibleMesh is hidden initially
		InvencibleMesh->SetupAttachment(RootComponent);
		InvencibleMesh->SetVisibility(false);
		InvencibleMesh->SetStaticMesh(InvencibleMesh2.Object);
	}

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

	//Patron Strategy
	bIsEstrategiaCamaraLentaActive = false;
	bIsEstrategiaRecuperacionActive = false;
	bIsEstrategiaExplosivaActive = false;
	bIsInvincible = false;
	PuntosJugador = 0;
	// Otras inicializaciones
	MaxVidas = 10;
	VidasRestantes = MaxVidas;
	MaxProyectiles = 100;
	ProyectilesRestantes = MaxProyectiles;
	MaxEnergia = 200;
	EnergiaRestante = MaxEnergia;
	
	
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
	PlayerInputComponent->BindAction("EstrategiaCamaraLenta1", IE_Pressed, this, &AAdapterPatern1Pawn::EstCamaraLenta);
	PlayerInputComponent->BindAction("EstrategiaRecuperacion2", IE_Pressed, this, &AAdapterPatern1Pawn::EstRecuperacion);
	PlayerInputComponent->BindAction("EstrategiaAtaque1", IE_Pressed, this, &AAdapterPatern1Pawn::EstAtaque1);
	PlayerInputComponent->BindAction("EstrategiaAtaque2", IE_Pressed, this, &AAdapterPatern1Pawn::EstAtaque2);
	PlayerInputComponent->BindAction("EstrategiaCambiarAatque1", IE_Pressed, this, &AAdapterPatern1Pawn::CambiarEstrategia1);
	PlayerInputComponent->BindAction("EstrategiaCambiarAatque2", IE_Pressed, this, &AAdapterPatern1Pawn::CambiarEstrategia2);
	PlayerInputComponent->BindAction("EstrategiaCambiarAatque3", IE_Pressed, this, &AAdapterPatern1Pawn::CambiarEstrategia3);
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
		// Reducir energía al moverse


		//EnergiaRestante -= DeltaSeconds * 2; // Ajusta el factor de reducción de energía según sea necesario
		//if (EnergiaRestante < 50)
		//{
		//	FString Message2 = FString::Printf(TEXT("Energia restante: %d "), ObtenerEnergiaRestante());
		//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, Message2);
		//}
		if (EnergiaRestante < 200)
		{
			EnergiaRestante += 0.2;

		}
		if (EnergiaRestante < 0)
		{
			EnergiaRestante = 0;
			// Manejar lo que sucede cuando la energía se agota, si es necesario
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);

	if (EstrategiaExplosiva)
	{
		EstrategiaExplosiva->Disparar();
	}
	if (EstrategiaAtaqueFinal)
	{
		EstrategiaAtaqueFinal->Disparar();

	}
}


void AAdapterPatern1Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (ProyectilesRestantes > 0)
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
				/*EnergiaRestante -= 2;*/
				/*FString Message2 = FString::Printf(TEXT("Energia restante: %d "), ObtenerEnergiaRestante());
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, Message2);*/

				ProyectilesRestantes--;
				FString Message = FString::Printf(TEXT("Proyectiles restantes: %d "), ObtenerProyectilesRestantes());
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, Message);
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
	if (!_Adaptador)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Adaptador is null"));
		return;
	}

	BounceBall = Cast<IIBounceBall>(_Adaptador);
	if (!BounceBall)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, TEXT("No se pudo instanciar"));
		return;
	}
}



void AAdapterPatern1Pawn::ReducirEnergia1()
{
	if (EnergiaRestante > 0)
		EnergiaRestante = EnergiaRestante - 10;
	if (EnergiaRestante < 10)
		MoveSpeed = -600;
	
	
	
		
}


void AAdapterPatern1Pawn::ReducirVida()
{
	if (VidasRestantes > 0)
		VidasRestantes--;
	if (VidasRestantes == 3)
	{
		InicializarEstadosJugador("ConEscudos");
		EstadoConEscudos ->ConEscudos();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
		
	}
	if (VidasRestantes == 9)
	{
		InicializarEstadosJugador("ConArmamentoAdicional");
		EstadoConArmamentoAdicional->ConArmamentoAdicional();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
		
	}
	if (VidasRestantes == 16)
	{
		InicializarEstadosJugador("ConCamuflaje");
		EstadoConCamuflaje->ConCamuflaje();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
	}
	if (VidasRestantes == 8)
	{
		InicializarEstadosJugador("Invensible");
		EstadoInvensible->Invencible();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *J_ObtenerEstadoActual()));
	}
	if (VidasRestantes <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Juego terminado"));
			
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
	// Configurar el temporizador para restaurar el estado básico después de 10 segundos
	

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
	//// Obtener la ubicación y rotación del pawn
	FVector PawnLocation = GetActorLocation();
	PawnLocation.Y += 200.0f;
	FRotator PawnRotation = GetActorRotation();


	ArmaIzquierda = GetWorld()->SpawnActor<AArmaAmiga>(PawnLocation, PawnRotation);
	if (ArmaIzquierda)
	{
		// Anclar el arma al jugador con las reglas de anclaje deseadas
		ArmaIzquierda->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

		// Ajustar la ubicación del arma después de anclarla
		FVector NewRelativeLocation = ArmaIzquierda->GetActorLocation();
		NewRelativeLocation.Y += 0.0f;
		ArmaIzquierda->SetActorLocation(NewRelativeLocation);
	}
		
		
}

void AAdapterPatern1Pawn::restaurarEstadoBasico()
{
	if (Estado == EstadoConEscudos)
	{
		// Lógica para desactivar el estado de escudos
		// Por ejemplo, eliminar el escudo
		if (Escudo)
		{
			Escudo->Destroy();
			Escudo = nullptr;
		}
	}
	
	else if (Estado == EstadoInvensible)
	{
		bIsInvincible = false;
		// Change mesh back to normal mesh
		InvencibleMesh->SetVisibility(false);
		ShipMeshComponent->SetVisibility(true);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Jugador invencible desactivado"));

		
	}
	else if (Estado == EstadoConCamuflaje)
	{
		// Lógica para desactivar el estado de camuflaje
	}

	// Restablecer al estado básico
	Estado = EstadoBasico;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estado desactivado, regresando al estado básico"));
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
	GetWorldTimerManager().SetTimer(TimerHandle_RestaurarEstadoBasico, this, &AAdapterPatern1Pawn::restaurarEstadoBasico, 10.0f, false);
}

void AAdapterPatern1Pawn::JugadorInvensible()
{

	bIsInvincible = true;
	
	// Change mesh to invincible mesh
	ShipMeshComponent->SetVisibility(false);
	InvencibleMesh->SetVisibility(true);

	GetWorldTimerManager().SetTimer(TimerHandle_RestaurarEstadoBasico, this, &AAdapterPatern1Pawn::restaurarEstadoBasico, 10.0f, false);
}

void AAdapterPatern1Pawn::JugadorConCamuflaje()
{
	
	
}



void AAdapterPatern1Pawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (bIsInvincible && OtherActor)
	{
		if (OtherActor->IsA(ANaveEnemigaCaza::StaticClass()) ||
			OtherActor->IsA(ANaveEnemigaEspia::StaticClass()) ||
			OtherActor->IsA(ANaveEnemigaNodriza::StaticClass()) ||
			OtherActor->IsA(ANaveEnemigaTransporte::StaticClass()))
		{
			// La nave enemiga está dentro del rango de destrucción
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nave enemiga destruida"));
			OtherActor->Destroy();
		}
	}
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
	EstrategiaAtaque = Cast<IIEstrategia>(_EstrategiaPawn);
	if (!EstrategiaAtaque)
	{ 
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo inicializar EstrategiaActual"));
	}
}

void AAdapterPatern1Pawn::EjecutarEstrategia()
{
	if (EstrategiaAtaque)
	{
		EstrategiaAtaque->Disparar();
	}
}

void AAdapterPatern1Pawn::AlternarEstrategiasTiempo(AActor* _EstrategiaPawn)
{
	EstrategiaTiempo = Cast<IIEstrategiasTiempo>(_EstrategiaPawn);
	if (!EstrategiaTiempo)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo inicializar EstrategiaActual"));
	}
}

void AAdapterPatern1Pawn::EjectuarEstrategiaTiempo()
{
	if (EstrategiaTiempo)
	{
		EstrategiaTiempo->EjecutarTiempo();
	}
}

void AAdapterPatern1Pawn::CambiarEstrategia(int32 NumeroEstrategia)
{
	AArmaAmiga* Arma = Cast<AArmaAmiga>(UGameplayStatics::GetActorOfClass(GetWorld(), AArmaAmiga::StaticClass()));
	Arma->CambiarEstrategia(NumeroEstrategia);
}

void AAdapterPatern1Pawn::CambiarEstrategia1()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia 1"));
	AArmaAmiga* Arma = Cast<AArmaAmiga>(UGameplayStatics::GetActorOfClass(GetWorld(), AArmaAmiga::StaticClass()));
	Arma->CambiarEstrategia(1);
}

void AAdapterPatern1Pawn::CambiarEstrategia2()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia 2"));
	AArmaAmiga* Arma = Cast<AArmaAmiga>(UGameplayStatics::GetActorOfClass(GetWorld(), AArmaAmiga::StaticClass()));
	Arma->CambiarEstrategia(2);
}

void AAdapterPatern1Pawn::CambiarEstrategia3()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia 3"));
	AArmaAmiga* Arma = Cast<AArmaAmiga>(UGameplayStatics::GetActorOfClass(GetWorld(), AArmaAmiga::StaticClass()));
	Arma->CambiarEstrategia(3);
}

void AAdapterPatern1Pawn::EstCamaraLenta()
{

	AlternarEstrategiasTiempo(EstrategiaCamaraLenta);
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
	else 
	{
		// Activar la estrategia si no está activa
		if (EstrategiaCamaraLenta)
		{
			EstrategiaCamaraLenta = GetWorld()->SpawnActor<AEstrategiaCamaraLenta>(AEstrategiaCamaraLenta::StaticClass());
			EjectuarEstrategiaTiempo();
			bIsEstrategiaCamaraLentaActive = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Camara Lenta Activada"));
		}
	}


}

void AAdapterPatern1Pawn::EstRecuperacion()
{


	    EstrategiaRecuperacion = GetWorld()->SpawnActor<AEstrategiaRecuperacion>(AEstrategiaRecuperacion::StaticClass());
		AlternarEstrategiasTiempo(EstrategiaRecuperacion);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Recuperacion"));
		EjectuarEstrategiaTiempo();
	
}

void AAdapterPatern1Pawn::EstAtaque1()
{
	    EstrategiaExplosiva = GetWorld()->SpawnActor<AEstrategiaExplosiva>(AEstrategiaExplosiva::StaticClass());
		AlternarEstrategias(EstrategiaExplosiva);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Explosiva"));
		EjecutarEstrategia();
}

void AAdapterPatern1Pawn::EstAtaque2()
{
	EstrategiaAtaqueFinal = GetWorld()->SpawnActor<AEstrategiaAtaqueFinal>(AEstrategiaAtaqueFinal::StaticClass());
	AlternarEstrategias(EstrategiaAtaqueFinal);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Estrategia Ataque Final"));
	EjecutarEstrategia();
}

void AAdapterPatern1Pawn::AgregarPuntos(int32 Puntos)
{
	PuntosJugador += Puntos;
	if (PuntosJugador >= 1200)
	{
		PuntosJugador = 0; // Resetear puntos a 0
		VidasRestantes = MaxVidas; // Restablecer vida al máximo
		EnergiaRestante = MaxEnergia; // Restablecer energía al máximo
		ProyectilesRestantes = MaxProyectiles; // Restablecer proyectiles al máximo
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("¡Vida y proyectiles restablecidos!"));
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Puntos: %d"), PuntosJugador));
	//AGREGAR EL MEMENTO PARA GUARDAR PARTIDA
	//MEJOARAR ESATRTEGIAS pa descativa y activar 
	//mEJORAR OBSERVER
	//AGREGAR PUAS
	//ELIMINAR SISTEMA DE PUNTUACION 
	//OPTIMIZAR JUEGO

}



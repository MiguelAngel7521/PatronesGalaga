// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoVisitor.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaTransporte.h"
#include "ComponenteEscudo.h"
#include "ComponenteArmas.h"
#include "AdapterPatern1Pawn.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Bomba.h"


// Sets default values
AMovimientoVisitor::AMovimientoVisitor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Radio = 300.0f; // Radio de la circunferencia
	Angulo = 600.0f; // �ngulo inicial
	Speed = 5.0f;


	// Inicializar variables para el movimiento por coordenadas
	currentTargetIndex = 0;
	coordinateSpeed = 1000.0f; // Velocidad del movimiento por coordenadas
	// Asignar coordenadas de destino
	targetLocations.Add(FVector(700, 2000, 200));    // Coordenada 1
	targetLocations.Add(FVector(600, 1000, 200));  // Coordenada 2
	targetLocations.Add(FVector(1510, 250, 200));  // Coordenada 3
	targetLocations.Add(FVector(1700, 80, 200));  // Coordenada 4
	targetLocations.Add(FVector(1510, -420, 200));  // Coordenada 5
	targetLocations.Add(FVector(1700, -960, 200));    // Coordenada 6
	targetLocations.Add(FVector(3100, -2200, 200));    // Coordenada 7

	//
	// Asignar coordenadas de destino
	targetLocations1.Add(FVector(-1000, 2000, 200));    // Coordenada 1
	targetLocations1.Add(FVector(700, 1000, 200));  // Coordenada 2
	targetLocations1.Add(FVector(-800, 250, 200));  // Coordenada 3
	targetLocations1.Add(FVector(-300, 80, 200));  // Coordenada 4
	targetLocations1.Add(FVector(-110, -420, 200));  // Coordenada 5
	targetLocations1.Add(FVector(-500, -960, 200));    // Coordenada 6
	targetLocations1.Add(FVector(-1000, -2200, 200));    // Coordenada 7

	// Asignar coordenadas de destino
	targetLocations2.Add(FVector(9000, -500, 200));    // Coordenada 1
	targetLocations2.Add(FVector(8500, -100, 200));  // Coordenada 2
	targetLocations2.Add(FVector(8000, -300, 200));  // Coordenada 3
	targetLocations2.Add(FVector(7500, 100, 200));  // Coordenada 4
	targetLocations2.Add(FVector(7110, 300, 200));  // Coordenada 5
	targetLocations2.Add(FVector(7300, 800, 200));    // Coordenada 6
	targetLocations2.Add(FVector(7500, 1060, 200));    // Coordenada 7






}

// Called when the game starts or when spawned
void AMovimientoVisitor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMovimientoVisitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AMovimientoVisitor::VisitNaveEnemigaCaza(ANaveEnemigaCaza* Nave)
{
	// MoivientoNaveEnemigaV(Nave, Nave->GetWorld()->GetDeltaSeconds()); 


		//Movimiento cada 10 s
		float DeltaTime = Nave->GetWorld()->GetDeltaSeconds();

	// Incrementar el tiempo transcurrido desde el �ltimo cambio de movimiento
	TiempoTranscurridoMovimiento += DeltaTime;

	// Determinar el tipo de movimiento actual basado en el tiempo transcurrido
	int32 TipoMovimiento = static_cast<int32>(FMath::FloorToInt(TiempoTranscurridoMovimiento / TiempoCambioMovimiento)) % NumMovimientos;

	// Realizar el movimiento correspondiente
	switch (TipoMovimiento)
	{
	case 0:
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	case 1:
		MoivientoNaveEnemiga1(Nave, DeltaTime);
		break;
	case 2:
		MoivientoNaveEnemiga3(Nave, DeltaTime);
		break;
	case 3:
		MoivientoNaveEnemiga3(Nave, DeltaTime);
		break;
	case 4:
		MoivientoNaveEnemiga3(Nave, DeltaTime);
		break;
	default:
		// Movimiento predeterminado
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	}

	// Si ha pasado el tiempo para cambiar el movimiento, reiniciar el contador
	if (TiempoTranscurridoMovimiento >= TiempoCambioMovimiento * NumMovimientos)
	{
		TiempoTranscurridoMovimiento = 0.0f;
	}

}

void AMovimientoVisitor::VisitNaveEnemigaEspia(ANaveEnemigaEspia* Nave)
{
	// MoivientoNaveEnemigaI(Nave, Nave->GetWorld()->GetDeltaSeconds()); 
		//Movimiento cada 10 s
		float DeltaTime = Nave->GetWorld()->GetDeltaSeconds();

	// Incrementar el tiempo transcurrido desde el �ltimo cambio de movimiento
	TiempoTranscurridoMovimiento += DeltaTime;

	// Determinar el tipo de movimiento actual basado en el tiempo transcurrido
	int32 TipoMovimiento = static_cast<int32>(FMath::FloorToInt(TiempoTranscurridoMovimiento / TiempoCambioMovimiento)) % NumMovimientos;

	// Realizar el movimiento correspondiente
	switch (TipoMovimiento)
	{
	case 0:
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	case 1:
		MoivientoNaveEnemiga1(Nave, DeltaTime);
		break;
	case 2:
		MoivientoNaveEnemiga3(Nave, DeltaTime);
		break;
	case 3:
		MoivientoNaveEnemiga3(Nave, DeltaTime);
		break;
	case 4:
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	default:
		// Movimiento predeterminado
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	}

	// Si ha pasado el tiempo para cambiar el movimiento, reiniciar el contador
	if (TiempoTranscurridoMovimiento >= TiempoCambioMovimiento * NumMovimientos)
	{
		TiempoTranscurridoMovimiento = 0.0f;
	}
}

void AMovimientoVisitor::VisitNaveEnemigaNodriza(ANaveEnemigaNodriza* Nave)
{
	// MoivientoNaveEnemigaS(Nave, Nave->GetWorld()->GetDeltaSeconds()); 
		//Movimiento cada 10 s
		float DeltaTime = Nave->GetWorld()->GetDeltaSeconds();

	// Incrementar el tiempo transcurrido desde el �ltimo cambio de movimiento
	TiempoTranscurridoMovimiento += DeltaTime;

	// Determinar el tipo de movimiento actual basado en el tiempo transcurrido
	int32 TipoMovimiento = static_cast<int32>(FMath::FloorToInt(TiempoTranscurridoMovimiento / TiempoCambioMovimiento)) % NumMovimientos;

	// Realizar el movimiento correspondiente
	switch (TipoMovimiento)
	{
	case 0:
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	case 1:
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	case 2:
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	case 3:
		MoivientoNaveEnemiga4(Nave, DeltaTime);
		break;
	case 4:
		MoivientoNaveEnemiga4(Nave, DeltaTime);
		break;
	default:
		// Movimiento predeterminado
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	}

	// Si ha pasado el tiempo para cambiar el movimiento, reiniciar el contador
	if (TiempoTranscurridoMovimiento >= TiempoCambioMovimiento * NumMovimientos)
	{
		TiempoTranscurridoMovimiento = 0.0f;
	}
}

void AMovimientoVisitor::VisitNaveEnemigaTransporte(ANaveEnemigaTransporte* Nave)
{
	float DeltaTime = Nave->GetWorld()->GetDeltaSeconds();

	// Incrementar el tiempo transcurrido desde el �ltimo cambio de movimiento
	TiempoTranscurridoMovimiento += DeltaTime;

	// Determinar el tipo de movimiento actual basado en el tiempo transcurrido
	int32 TipoMovimiento = static_cast<int32>(FMath::FloorToInt(TiempoTranscurridoMovimiento / TiempoCambioMovimiento)) % NumMovimientos;

	// Realizar el movimiento correspondiente
	switch (TipoMovimiento)
	{
	case 0:
		MoverBomba(Nave, DeltaTime);
		break;
	case 1:
		MoivientoNaveEnemiga1(Nave, DeltaTime);
		break;
	case 2:
		MoivientoNaveEnemiga1(Nave, DeltaTime);
		break;
	case 3:
		MoverBomba(Nave, DeltaTime);
		break;
	case 4:
		MoivientoNaveEnemiga3(Nave, DeltaTime);
		break;
	default:
		// Movimiento predeterminado
		MoivientoNaveEnemiga(Nave, DeltaTime);
		break;
	}

	// Si ha pasado el tiempo para cambiar el movimiento, reiniciar el contador
	if (TiempoTranscurridoMovimiento >= TiempoCambioMovimiento * NumMovimientos)
	{
		TiempoTranscurridoMovimiento = 0.0f;
	}
}

void AMovimientoVisitor::VisitComponenteEscudo(AComponenteEscudo* Componente)
{
	////Movimiento cada 10 s
	//float DeltaTime = Componente->GetWorld()->GetDeltaSeconds();

	//// Incrementar el tiempo transcurrido desde el �ltimo cambio de movimiento
	//TiempoTranscurridoMovimiento += DeltaTime;

	//// Determinar el tipo de movimiento actual basado en el tiempo transcurrido
	//int32 TipoMovimiento = static_cast<int32>(FMath::FloorToInt(TiempoTranscurridoMovimiento / TiempoCambioMovimiento)) % NumMovimientos;

	//// Realizar el movimiento correspondiente
	//switch (TipoMovimiento)
	//{
	//case 0:
	//	MoivientoNaveEnemiga(Componente, DeltaTime);
	//	break;
	//case 1:
	//	MoivientoNaveEnemiga1(Componente, DeltaTime);
	//	break;
	//case 2:
	//	MoivientoNaveEnemiga3(Componente, DeltaTime);
	//	break;
	//case 3:
	//	MoivientoNaveEnemiga3(Componente, DeltaTime);
	//	break;
	//case 4:
	//	MoivientoNaveEnemiga3(Componente, DeltaTime);
	//	break;
	//default:
	//	// Movimiento predeterminado
	//	MoivientoNaveEnemiga(Componente, DeltaTime);
	//	break;
	//}

	//// Si ha pasado el tiempo para cambiar el movimiento, reiniciar el contador
	//if (TiempoTranscurridoMovimiento >= TiempoCambioMovimiento * NumMovimientos)
	//{
	//	TiempoTranscurridoMovimiento = 0.0f;
	//}
}

void AMovimientoVisitor::VisitComponenteArmas(AComponenteArmas* Componente)
{
	////Movimiento cada 10 s
	//float DeltaTime = Componente->GetWorld()->GetDeltaSeconds();

	//// Incrementar el tiempo transcurrido desde el �ltimo cambio de movimiento
	//TiempoTranscurridoMovimiento += DeltaTime;

	//// Determinar el tipo de movimiento actual basado en el tiempo transcurrido
	//int32 TipoMovimiento = static_cast<int32>(FMath::FloorToInt(TiempoTranscurridoMovimiento / TiempoCambioMovimiento)) % NumMovimientos;

	//// Realizar el movimiento correspondiente
	//switch (TipoMovimiento)
	//{
	//case 0:
	//	MoivientoNaveEnemiga(Componente, DeltaTime);
	//	break;
	//case 1:
	//	MoivientoNaveEnemiga1(Componente, DeltaTime);
	//	break;
	//case 2:
	//	MoivientoNaveEnemiga3(Componente, DeltaTime);
	//	break;
	//case 3:
	//	MoivientoNaveEnemiga3(Componente, DeltaTime);
	//	break;
	//case 4:
	//	MoivientoNaveEnemiga3(Componente, DeltaTime);
	//	break;
	//default:
	//	// Movimiento predeterminado
	//	MoivientoNaveEnemiga(Componente, DeltaTime);
	//	break;
	//}

	//// Si ha pasado el tiempo para cambiar el movimiento, reiniciar el contador
	//if (TiempoTranscurridoMovimiento >= TiempoCambioMovimiento * NumMovimientos)
	//{
	//	TiempoTranscurridoMovimiento = 0.0f;
	//}
}

void AMovimientoVisitor::MoivientoNaveEnemiga(AActor* Nave, float DeltaTime)
{
	//MOvimiento 1

	Angulo += Speed * DeltaTime;

	float NuevaY = Nave->GetActorLocation().Y + Radio * FMath::Sin(Angulo) * DeltaTime;

	FVector NewLocation = FVector(Nave->GetActorLocation().X, NuevaY, Nave->GetActorLocation().Z);
	Nave->SetActorLocation(NewLocation);
}

void AMovimientoVisitor::MoivientoNaveEnemiga1(AActor* Nave, float DeltaTime)
{


	FVector newLocation = Nave->GetActorLocation();
	FVector targetLocation = targetLocations[currentTargetIndex];
	FVector direction = (targetLocation - newLocation).GetSafeNormal();
	float distance = FVector::Distance(targetLocation, newLocation);
	newLocation += direction * coordinateSpeed * DeltaTime;

	Nave->SetActorLocation(newLocation);

	// Verificar si la nave ha llegado a la ubicaci�n de destino actual
	if (distance < 20.0f)
	{
		// Mover a la siguiente ubicaci�n de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations.Num();
	}

}

void AMovimientoVisitor::MoivientoNaveEnemiga2(AActor* Nave, float DeltaTime)
{
	// Movimiento formando la letra "O"
	FVector CurrentLocation = Nave->GetActorLocation();
	float Radius = 500.0f; // Radio del movimiento circular
	float Speed1 = 10.0f;  // Velocidad del movimiento

	float Time = GetWorld()->GetTimeSeconds();
	float Angle = Speed1 * Time;
	float X = Radius * FMath::Cos(Angle);
	float Y = Radius * FMath::Sin(Angle);

	FVector NewLocation = FVector(X, Y, CurrentLocation.Z);
	Nave->SetActorLocation(NewLocation);


	//Movimiento de giro manteniendo la posici�n en Y
	// Movimiento formando giros sin cambiar la altura Z



}

void AMovimientoVisitor::MoivientoNaveEnemiga3(AActor* Nave, float DeltaTime)
{

	// Movimiento de arriba a abajo
	if (targetLocations1.Num() == 0) return;  // Verificar que haya coordenadas definidas

	FVector NewLocation = Nave->GetActorLocation();
	FVector TargetLocation = targetLocations1[currentTargetIndex];
	FVector Direction = (TargetLocation - NewLocation).GetSafeNormal();
	float Distance = FVector::Distance(TargetLocation, NewLocation);
	NewLocation += Direction * coordinateSpeed * DeltaTime;
	Nave->SetActorLocation(NewLocation);

	// Verificar si la nave ha llegado a la ubicaci�n de destino actual
	if (Distance < 20.0f)
	{
		// Mover a la siguiente ubicaci�n de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations1.Num();
	}
}

void AMovimientoVisitor::MoivientoNaveEnemiga4(AActor* Nave, float DeltaTime)
{

	// Movimiento de derecha a izquierda

	FVector NewLocation = Nave->GetActorLocation();
	FVector TargetLocation = targetLocations2[currentTargetIndex];
	FVector Direction = (TargetLocation - NewLocation).GetSafeNormal();
	float Distance = FVector::Distance(TargetLocation, NewLocation);
	NewLocation += Direction * coordinateSpeed * DeltaTime;
	Nave->SetActorLocation(NewLocation);
	if (Distance < 20.0f)
	{
		// Mover a la siguiente ubicaci�n de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations2.Num();
	}
}

void AMovimientoVisitor::MoverBomba(AActor* Bomba, float DeltaTime)
{
	// Mover la nave en el eje Z
	 // Obtener la posici�n actual de la nave
	FVector CurrentLocation = Bomba->GetActorLocation();

	// Mover la nave en el eje Z hasta que alcance la altitud de 700
	if (CurrentLocation.Z < 700.0f)
	{
		CurrentLocation.Z += coordinateSpeed * DeltaTime;
		if (CurrentLocation.Z > 700.0f) // Asegurarse de no pasar de 700
		{
			CurrentLocation.Z = 700.0f;
		}
		Bomba->SetActorLocation(CurrentLocation);
	}
	// Ensure AleX and AleY have initial random values if not set
	if (AleX == 0 && AleY == 0)
	{
		AleX = FMath::RandRange(-1800, 1800);
		AleY = FMath::RandRange(-1800, 1800);
	}

	FVector NaveLocation = Bomba->GetActorLocation();

	if (NaveLocation.X <= AleX + 50 && NaveLocation.X >= AleX - 50 && NaveLocation.Y <= AleY + 50 && NaveLocation.Y >= AleY - 50)
	{
		AleX = FMath::RandRange(-1800, 1800);
		AleY = FMath::RandRange(-1800, 1800);

		UWorld* const World = GetWorld();
		if (World)
		{
			FVector BombPosition = NaveLocation + FVector(-50, 0, -50);
			FRotator BombRotation = FRotator(0, 0, 0);

			// Spawn the bomb
			World->SpawnActor<ABomba>(BombPosition, BombRotation);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Creando bomba")));

			tmpBomb = 0;
			tmpSuelto = FMath::RandRange(3, 6); // Random time between 3 to 6 seconds
		}
	}
	else
	{
		FVector Direction = FVector::ZeroVector;

		if (NaveLocation.X > AleX)
			Direction.X = -1;
		else if (NaveLocation.X < AleX)
			Direction.X = 1;

		if (NaveLocation.Y > AleY)
			Direction.Y = -1;
		else if (NaveLocation.Y < AleY)
			Direction.Y = 1;

		Direction.Normalize();
		FVector NewLocation = NaveLocation + Direction * 400 * DeltaTime;
		Bomba->SetActorLocation(NewLocation);
	}
}








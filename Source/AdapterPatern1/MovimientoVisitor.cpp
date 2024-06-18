// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoVisitor.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaTransporte.h"
#include "ComponenteEscudo.h"
#include "ComponenteArmas.h"


// Sets default values
AMovimientoVisitor::AMovimientoVisitor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Radio = 300.0f; // Radio de la circunferencia
	Angulo = 600.0f; // Ángulo inicial
	Speed = 5.0f;


	// Inicializar variables para el movimiento por coordenadas
	currentTargetIndex = 0;
	coordinateSpeed = 1000.0f; // Velocidad del movimiento por coordenadas
	// Asignar coordenadas de destino
	targetLocations.Add(FVector(-300, 3000, 200));    // Coordenada 1
	targetLocations.Add(FVector(-700, 2000, 200));  // Coordenada 2
	targetLocations.Add(FVector(-510, 1250, 200));  // Coordenada 3
	targetLocations.Add(FVector(-700, 80, 200));  // Coordenada 4
	targetLocations.Add(FVector(-510, -920, 200));  // Coordenada 5
	targetLocations.Add(FVector(-700, -1960, 200));    // Coordenada 6
	targetLocations.Add(FVector(-300, -3200, 200));    // Coordenada 7

	//
	// Asignar coordenadas de destino
	targetLocations1.Add(FVector(-1000, 3000, 200));    // Coordenada 1
	targetLocations1.Add(FVector(-2500, 2000, 200));  // Coordenada 2
	targetLocations1.Add(FVector(-1110, 1250, 200));  // Coordenada 3
	targetLocations1.Add(FVector(-2500, 80, 200));  // Coordenada 4
	targetLocations1.Add(FVector(-1110, -920, 200));  // Coordenada 5
	targetLocations1.Add(FVector(-2500, -1960, 200));    // Coordenada 6
	targetLocations1.Add(FVector(-1000, -3200, 200));    // Coordenada 7

	// Asignar coordenadas de destino
	targetLocations2.Add(FVector(-2000, 0, 200));    // Coordenada 1
	targetLocations2.Add(FVector(-1000, 0, 200));  // Coordenada 2
	targetLocations2.Add(FVector(-500, 0, 200));  // Coordenada 3
	targetLocations2.Add(FVector(-1500, 0, 200));  // Coordenada 4
	targetLocations2.Add(FVector(-510, 0, 200));  // Coordenada 5
	targetLocations2.Add(FVector(-1500, 0, 200));    // Coordenada 6
	targetLocations2.Add(FVector(-2000, -0, 200));    // Coordenada 7






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

	// Incrementar el tiempo transcurrido desde el último cambio de movimiento
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

	// Incrementar el tiempo transcurrido desde el último cambio de movimiento
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

	// Incrementar el tiempo transcurrido desde el último cambio de movimiento
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
		MoivientoNaveEnemiga1(Nave, DeltaTime);
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

void AMovimientoVisitor::VisitNaveEnemigaTransporte(ANaveEnemigaTransporte* Nave)
{/*
	MoivientoNaveEnemigaI2(Nave, Nave->GetWorld()->GetDeltaSeconds());*/
	//Movimiento cada 10 s
	float DeltaTime = Nave->GetWorld()->GetDeltaSeconds();

	// Incrementar el tiempo transcurrido desde el último cambio de movimiento
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
		MoivientoNaveEnemiga1(Nave, DeltaTime);
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

void AMovimientoVisitor::VisitComponenteEscudo(AComponenteEscudo* Componente)
{
	////Movimiento cada 10 s
	//float DeltaTime = Componente->GetWorld()->GetDeltaSeconds();

	//// Incrementar el tiempo transcurrido desde el último cambio de movimiento
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

	//// Incrementar el tiempo transcurrido desde el último cambio de movimiento
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

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (distance < 20.0f)
	{
		// Mover a la siguiente ubicación de destino
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


	//Movimiento de giro manteniendo la posición en Y
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

	// Verificar si la nave ha llegado a la ubicación de destino actual
	if (Distance < 20.0f)
	{
		// Mover a la siguiente ubicación de destino
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
		// Mover a la siguiente ubicación de destino
		currentTargetIndex = (currentTargetIndex + 1) % targetLocations2.Num();
	}
}








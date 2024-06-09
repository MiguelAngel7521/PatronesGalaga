// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoVisitor.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaTransporte.h"


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
	MoivientoNaveEnemiga1(Nave, Nave->GetWorld()->GetDeltaSeconds());

}

void AMovimientoVisitor::VisitNaveEnemigaEspia(ANaveEnemigaEspia* Nave)
{
	MoivientoNaveEnemiga2(Nave, Nave->GetWorld()->GetDeltaSeconds());
}

void AMovimientoVisitor::VisitNaveEnemigaNodriza(ANaveEnemigaNodriza* Nave)
{
	MoivientoNaveEnemiga3(Nave, Nave->GetWorld()->GetDeltaSeconds());
}

void AMovimientoVisitor::VisitNaveEnemigaTransporte(ANaveEnemigaTransporte* Nave)
{
	MoivientoNaveEnemiga4(Nave, Nave->GetWorld()->GetDeltaSeconds());
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
	if (distance < 10.0f)
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
	float Speed1 = 100.0f;  // Velocidad del movimiento

	float Time = GetWorld()->GetTimeSeconds();
	float Angle = Speed1 * Time;
	float X = Radius * FMath::Cos(Angle);
	float Y = Radius * FMath::Sin(Angle);

	FVector NewLocation = FVector(X, Y, CurrentLocation.Z);
	Nave->SetActorLocation(NewLocation);
}

void AMovimientoVisitor::MoivientoNaveEnemiga3(AActor* Nave, float DeltaTime)
{
	// Movimiento de arriba a abajo
	FVector CurrentLocation = Nave->GetActorLocation();
	float Speed2 = 200.0f; // Velocidad del movimiento

	float Time = GetWorld()->GetTimeSeconds();
	float Offset = Speed2 * FMath::Sin(Time);

	FVector NewLocation = CurrentLocation + FVector(0, 0, Offset);
	Nave->SetActorLocation(NewLocation);
}

void AMovimientoVisitor::MoivientoNaveEnemiga4(AActor* Nave, float DeltaTime)
{

	// Movimiento de derecha a izquierda
	FVector CurrentLocation = Nave->GetActorLocation();
	float Speed3 = 100.0f; // Velocidad del movimiento

	float Time = GetWorld()->GetTimeSeconds();
	float Offset = Speed3 * Time;

	FVector NewLocation = CurrentLocation + FVector(0, -Offset, 0);
	Nave->SetActorLocation(NewLocation);
}


// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEnemigaVisitor.h"
#include "MovimientoVisitor.generated.h"

UCLASS()
class ADAPTERPATERN1_API AMovimientoVisitor : public AActor, public IINaveEnemigaVisitor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovimientoVisitor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void VisitNaveEnemigaCaza(class ANaveEnemigaCaza* Nave) override;
	void VisitNaveEnemigaEspia(class ANaveEnemigaEspia* Nave) override;
	void VisitNaveEnemigaNodriza(class ANaveEnemigaNodriza* Nave) override;
	void VisitNaveEnemigaTransporte(class ANaveEnemigaTransporte* Nave)override;
    void VisitComponenteEscudo(class AComponenteEscudo* Componente) override;
	void VisitComponenteArmas(class AComponenteArmas* Componente) override ;
	void MoivientoNaveEnemiga(AActor* Nave, float DeltaTime);
	void MoivientoNaveEnemiga1(AActor* Nave, float DeltaTime);
	void MoivientoNaveEnemiga2(AActor* Nave, float DeltaTime);
	void MoivientoNaveEnemiga3(AActor* Nave, float DeltaTime);
	void MoivientoNaveEnemiga4(AActor* Nave, float DeltaTime);
	// Variables para el movimiento por coordenadas
	TArray<FVector> targetLocations;
	TArray<FVector> targetLocations1;
	TArray<FVector> targetLocations2;
	TArray<FVector> targetLocations3;
	int32 currentTargetIndex;
	float coordinateSpeed;


	// Velocidad de movimiento de la nave
	float speed = 1000.0f;
	float Radio; // Radio de la circunferencia
	float Angulo; // Ángulo inicial
	float Speed; // Velocidad de rotación
	// Variables para el cambio de movimientos
	float TiempoTranscurridoMovimiento = 0.0f;
	float TiempoCambioMovimiento = 10.0f; // Tiempo en segundos antes de cambiar de movimiento
	int32 NumMovimientos = 5;


};

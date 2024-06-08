// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ANaveEnemigaTransporte : public ANaveEnemiga
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaTime) override;


	void DescargarContenido();


	void ActivarArmasDefensivas();


	void RecogerRecursos();


	void IntercambiarRecursos();

	void ReabastecerNaves();
public:
	ANaveEnemigaTransporte();
	virtual void Mover(float DeltaTime);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
	float TiempoDescarga;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
	float ArmasDefensivas;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Nave Enemiga Nodriza")
	float CapacidadCarga;

	//Patron Observer
	void SuscribirRadar(AActor* Radar);
	void NotificarRadar();

private:
	TArray<AActor*> Observers;

	// Lista de coordenadas de destino
	TArray<FVector> targetLocations;

	// Índice de la ubicación de destino actual
	int32 currentTargetIndex;

	// Velocidad de movimiento de la nave
	float speed = 1000.0f;


};

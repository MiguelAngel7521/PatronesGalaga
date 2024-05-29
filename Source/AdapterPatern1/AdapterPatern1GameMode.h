// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AdapterPatern1GameMode.generated.h"

UCLASS(MinimalAPI)
class AAdapterPatern1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAdapterPatern1GameMode();
protected:
	virtual void BeginPlay() override;
	//Patron Facade 
	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class ACapsulasFacade* Facade;


public:
	UPROPERTY(VisibleAnywhere, Category = "Game Mode")
	class AAdapterPatern1Pawn* Jugador;
	UPROPERTY(VisibleAnywhere, Category = "Game Mode")
	class ABallAdapter* Adapter;
public:
	//TArray<ANaveEnemiga*> TANavesEnemigas;
	//TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	//TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	//TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;
	//TArray<ANaveEnemigaNodriza*> TANavesEnemigasNodriza;

	void ActualizarPosicionesNavesEnemigas();
	void MostrarPosicionesNavesEnemigas();
	void DetenerProceso();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NavesEnemigas")
	//TMap<ANaveEnemiga*, FVector> TMPosicionesNavesEnemigas;



	FTimerHandle ManejadorEliminarNaves;
	FTimerHandle ManejadorCrearNaves;
	FTimerHandle ManejadorMostrarPosiciones;
	FTimerHandle ManejadorDetenerProceso;

public:

	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle ManejadorTemporizador;
public:
	//Patron Builder
	class AIngenieroEspecialista1* Ingeniero;
	class AIngenieroEspecialista2* Ingeniero2;
	class AIngenieroEspecialista3* Ingeniero3;
	class ADirectorBuilder* Director;


	int Tiempo;
	int Cantidad;

private:
	int32 Cont;
	float TimerController;

	//UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
	//AConcretoBuilderPaquetesEnergia* ConstructorPaquetesEnergia;

	//UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
	//ADirectorPaquetesEnergia* Director;

	//Patron State 
	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class ARadarEnemigo* Radar;
	
};





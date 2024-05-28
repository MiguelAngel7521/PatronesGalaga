// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstados.h"
#include "EstadoConCamuflaje.generated.h"

UCLASS()
class ADAPTERPATERN1_API AEstadoConCamuflaje : public AActor, public IIEstados
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoConCamuflaje();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(VisibleAnywhere, Category = "Estado Con Canmuflaje")
	AAdapterPatern1Pawn* Jugador;

public:

	//Establecemos el jugador
	void EstablecerJugador(class AAdapterPatern1Pawn* _Jugador) override;
	//Establecemos los diferentes estados
	void ConCamuflaje() override;
	//Visualizamos los estados actuales del jugador
	FString ObtenerEstado() override;

private:
	void ConArmamentoAdicional() override {};
	void Basico() override {};
	void ConEscudos() override {};
	void Invencible() override {};
	void ConRadar() override {};

};

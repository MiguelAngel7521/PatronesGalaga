// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "CapsulasTipoFacade.generated.h"

UCLASS()
class ADAPTERPATERN1_API ACapsulasTipoFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsulasTipoFacade();

	class ACapsulaVida* CapsulaDeVida;
	//class ACapsulaDeMunicion* CapsulaDeMunicion;
	class ACapsulaEnergia* CapsulaDeEnergia;
	class ACapsulaVelocidad* CapsulaDeVelocidad;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CrearCapsulaDeVida(); //Vida
	void CrearCapsulaDeEnergia(); //Potencia
	void CrearCapsulaDeVelocidad(); //Velocidad
	void BloquearCapsula(); //Bloquear

	void CrearEscuadronEnemigos1(); //Escuadron1
	void CrearEscuadronEnemigos2(); //Escuadron2
	void CrearEscuadronEnemigos3(); //Escuadron3

	void CrearObstaculos(); //Obstaculo1
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandleCapsulaVida;
	FTimerHandle TimerHandleCapsulaEnergia;
	FTimerHandle TimerHandleCapsulaVelocidad;
	void IniciarCreacionCapsulas();
	

public:
	void RecibirOrden(const TArray<FString>& _Orden);
	void CrearOrden(const FString& _Orden);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	//Patron Builder
	class AIngenieroEspecialista1* Ingeniero;
	class AIngenieroEspecialista2* Ingeniero2;
	class AIngenieroEspecialista3* Ingeniero3;
	class ADirectorBuilder* Director;
	class AProxyNaveCompuesta* Proxy;

private:
	TArray<ANaveEnemiga*> NavesEnemigas;


};

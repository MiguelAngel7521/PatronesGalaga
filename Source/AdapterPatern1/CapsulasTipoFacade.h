// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	//void CrearCapsulaDeMunicion(); //Potencia
	void CrearCapsulaDeEnergia(); //Potencia
	void CrearCapsulaDeVelocidad(); //Velocidad
	void BloquearCapsula(); //Bloquear

public:
	void RecibirOrden(const TArray<FString>& _Orden);
	void CrearOrden(const FString& _Orden);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS()
class ADAPTERPATERN1_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaNaveEnemiga;

protected:
	float velocidad;
	float velocidadDisparo;
	float resistencia;
	float danoProducido;
	float valorDestruccion;
	float recompensa;
	float energia;
	float tiempoDisparo;
	float tiempoReaparicion;
	FString nombre;
	FVector posicion;
	FVector ubicacionActual;
	float Radio; // Radio de la circunferencia
	float Angulo; // Ángulo inicial
	float Speed; // Velocidad de rotación

	int Score;
	int ScorePorEnemigo;

	/*UAComponenteMovimiento* MovimientoNavesComponent;*/


	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

public:
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetVelocidadDisparo() const { return velocidadDisparo; }
	FORCEINLINE float GetResistencia() const { return resistencia; }
	FORCEINLINE float GetDanoProducido() const { return danoProducido; }
	FORCEINLINE float GetValorDestruccion() const { return valorDestruccion; }
	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE float GetRecompensa() const { return recompensa; }
	FORCEINLINE float GetEnergia() const { return energia; }
	FORCEINLINE float GetTiempoReaparicion() const { return tiempoReaparicion; }
	FORCEINLINE FString GetNombre() const { return nombre; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE FVector GetUbicacionActual() const { return ubicacionActual; }


	//Set
	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetVelocidadDisparo(float _velocidadDisparo) { velocidadDisparo = _velocidadDisparo; }
	FORCEINLINE void SetResistencia(float _resistencia) { resistencia = _resistencia; }
	FORCEINLINE void SetValorDestruccion(float _valorDestruccion) { valorDestruccion = _valorDestruccion; }
	FORCEINLINE void SetDanoProducido(float _danoProducido) { danoProducido = _danoProducido; }
	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetRecompensa(float _recompensa) { recompensa = _recompensa; }
	FORCEINLINE void SetEnergia(float _energia) { energia = _energia; }
	FORCEINLINE void SetTiempoReaparicion(float _tiempoReaparicion) { tiempoReaparicion = _tiempoReaparicion; }
	FORCEINLINE void SetNombre(FString _nombre) { nombre = _nombre; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetUbicacionActual(FVector _ubicacionActual) { ubicacionActual = _ubicacionActual; }

public:
	// Sets default values for this actor's properties
	ANaveEnemiga();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void FireProjectile();
	float FireRate;
	FTimerHandle FireTimerHandle;



	int GetScore() const { return Score; }

	void AumentarPoints()
	{
		if (Score <= 0)

			Score += 50;

	}
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Variable que almacena el valor de puntuación de la nave enemiga

	virtual void DestruirNaveEnemiga();


};

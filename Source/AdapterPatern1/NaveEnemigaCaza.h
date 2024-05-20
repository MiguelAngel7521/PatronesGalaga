// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "SistemaPuntuacionComponente.h"
#include "NaveEnemigaCaza.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()
	
protected:
	float HiperVelocidad;
	int NumeroMisiles;
	bool RayosLaserActivos;
	float DanoRayoLaser; 
	float TiempoEntreRayosLaser;
	virtual void BeginPlay() override;
private:
	TArray<FVector> SecuenciaZ;
	int32 IndiceActual;
	FVector Objetivo;
	float Velocidad;

	int cantidadBombas;
	float tiempoExplosion = 0;
	float TiempoTranscurrido = 0;

	

public:
	ANaveEnemigaCaza();
	virtual void Tick(float DeltaTime) override;
	void ActivarRayoLaser();
	void DescativarRayoLaser();
	void DispararRayoLaser();
	void DispararMisiles();
	virtual void mover(float DeltaTime);
	virtual void FireProjectile() override;
    

public:


	UPROPERTY(EditAnywhere, Category = "Proyectil")
	TSubclassOf<class AProjectileEnemigo> ProyectilEnemigoClass;

	UPROPERTY(EditAnywhere, Category = "Proyectil")
	float FireRate;

	float FireCooldown;
	


	static USistemaPuntuacionComponente* SharedSistemaPuntuacionComponente;

	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

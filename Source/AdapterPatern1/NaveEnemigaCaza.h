// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "SistemaPuntuacionComponente.h"
#include "ISuscriptor.h"
#include "NaveEnemigaCaza.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ANaveEnemigaCaza : public ANaveEnemiga/*, public IISuscriptor*/
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

	//Etiqueta
	UPROPERTY(EditAnywhere, Category = "Etiquetas")
	FString EtiquetaPersonalizada = "Radar";
    

public:


	UPROPERTY(EditAnywhere, Category = "Proyectil")
	TSubclassOf<class AProjectileEnemigo> ProyectilEnemigoClass;

	UPROPERTY(EditAnywhere, Category = "Proyectil")
	float FireRate;
	float FireCooldown;
	static USistemaPuntuacionComponente* SharedSistemaPuntuacionComponente;

	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//Patron Observer 
	void SuscribirRadar(AActor* RadarHDU);
	void NotificarRadar();

private:
	TArray<AActor*> Observers;

	//Patron Observer Ingeniero
public:
	virtual void Actualizar(const FString& Accion) ;
	virtual float ObtenerEnergia() const;
	class ArmaAmiga* ArmaAmiga;

public:
	FVector UltimaPosicionArma;
	float Energia;
	bool bReabasteciendo;

	void EvitarArma();
	void DirigirseReabastecimiento();

};

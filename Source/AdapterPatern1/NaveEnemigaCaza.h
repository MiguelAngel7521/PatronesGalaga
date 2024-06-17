// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "SistemaPuntuacionComponente.h"
#include "ISuscriptor.h"
#include "INaveEnemigaVisitor.h"
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


	//Patron Observer 
	void SuscribirRadar(AActor* RadarHDU);
	void NotificarRadar();

private:
	TArray<AActor*> Observers;

	//Patron Observer Ingeniero
public:
	virtual void Actualizar(const FString& Accion);
	class ArmaAmiga* ArmaAmiga;


	//Patron Visitor
	
	void Accept(IINaveEnemigaVisitor* Visitor) override ;
private:
	// Visitor instance
	class AMovimientoVisitor* MovimientoVisitor;
	class ARecuperacionVisitor* RecuperacionVisitor;
	class AAtaqueVisitor* AtaqueVisitor;

};

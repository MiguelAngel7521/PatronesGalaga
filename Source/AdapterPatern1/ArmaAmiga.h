// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstrategiasAtaquesPawn.h"
#include "ArmaAmiga.generated.h"

UCLASS()
class ADAPTERPATERN1_API AArmaAmiga : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AArmaAmiga();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaArmas;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Proyectil
	void FireProjectile();
	UPROPERTY(EditAnywhere, Category = "Proyectil")
	TSubclassOf<class AProjectileEnemigo> ProyectilEnemigoClass;

	UPROPERTY(EditAnywhere, Category = "Proyectil")
	float FireRate;

	float FireCooldown;
	FTimerHandle FireTimerHandle;
	int Vida;
	void RecibirDano();

	class ANaveEnemigaCaza* NaveEnemigaCaza;
private:
	FVector PosicionActual;
	class ARadarEnemigo* Radar;

	void NotificarRadar();
	//Arma
	public:
		void SetEstrategia(AActor* EstrategiaActual);

		void CambiarEstrategia(int32 NumeroEstrategia);

		class AEstrategiaArmaEscudo* EstrategiaEscudo;
		class AEstrategiaAtaqueSierra* EstrategiaSierra;
		class AEstrategiaAtaqueNormal* EstrategiaNormal;
		void CambiarMalla(UStaticMesh* MallaNueva);
private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	IIEstrategiasAtaquesPawn* Estrategia;

	

};

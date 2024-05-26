// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
private:
	FVector PosicionActual;
	class ARadarEnemigo* Radar;

	void NotificarRadar();

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEnemigaVisitor.h"
#include "ComponenteArmas.generated.h"

UCLASS()
class ADAPTERPATERN1_API AComponenteArmas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponenteArmas();

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
	int vida = 3;
	void RecibirDanio();

	// Lista de coordenadas de destino
	TArray<FVector> targetLocations;

	// �ndice de la ubicaci�n de destino actual
	int32 currentTargetIndex;

	// Velocidad de movimiento de la nave
	float speed = 1000.0f;
	//Patron Visitor
	virtual void Accept(IINaveEnemigaVisitor* Visitor);
private:
	// Visitor instance
	class AMovimientoVisitor* MovimientoVisitor;
	class ARecuperacionVisitor* RecuperacionVisitor;
	class AAtaqueVisitor* AtaqueVisitor;


};
 
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.h"
#include "FabricaObstaculos.generated.h"

UCLASS()
class ADAPTERPATERN1_API AFabricaObstaculos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaObstaculos();
	UPROPERTY(EditAnywhere, Category = "Obstaculo")
	TSubclassOf<AObstaculo> ObstaculoClass;

	UFUNCTION(BlueprintCallable)
	void GenerarObstaculos(int32 CantidadObstaculos, FVector MinSpawnLocation, FVector MaxSpawnLocation, float MinMoveSpeed, float MaxMoveSpeed);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TArray<AObstaculo*> Obstaculos;
	FTimerHandle TimerHandle;

	FVector GetRandomSpawnLocation(FVector MinSpawnLocation, FVector MaxSpawnLocation);
	float GetRandomMoveSpeed(float MinMoveSpeed, float MaxMoveSpeed);
	void DestroyObstaculos();

};

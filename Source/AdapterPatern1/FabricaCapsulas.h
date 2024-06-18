// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.h"
#include "FabricaCapsulas.generated.h"

UCLASS()
class ADAPTERPATERN1_API AFabricaCapsulas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaCapsulas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GenerarCapsula();
	FVector GetRandomSpawnLocation();
	TSubclassOf<ACapsula> ObtenerClaseCapsula();

	UPROPERTY(EditAnywhere, Category = "Spawn Range")
	float RangoSpawnX;

	UPROPERTY(EditAnywhere, Category = "Spawn Range")
	float RangoSpawnY;

	FTimerHandle TimerHandle;

};

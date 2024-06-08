// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstrategiasTiempo.h"
#include "EstrategiaCamaraLenta.generated.h"

UCLASS()
class ADAPTERPATERN1_API AEstrategiaCamaraLenta : public AActor,public IIEstrategiasTiempo
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaCamaraLenta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void EjecutarTiempo() override;
	class AAdapterPatern1Pawn* Pawn;

};

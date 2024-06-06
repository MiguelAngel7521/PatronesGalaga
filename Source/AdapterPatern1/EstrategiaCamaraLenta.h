// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstrategia.h"
#include "EstrategiaCamaraLenta.generated.h"

UCLASS()
class ADAPTERPATERN1_API AEstrategiaCamaraLenta : public AActor,public IIEstrategia
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
	void EjecutarEstrategia() override;
	class AAdapterPatern1Pawn* Pawn;

};

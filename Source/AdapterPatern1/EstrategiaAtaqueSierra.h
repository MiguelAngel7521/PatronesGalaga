// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstrategiasAtaquesPawn.h"
#include "EstrategiaAtaqueSierra.generated.h"

UCLASS()
class ADAPTERPATERN1_API AEstrategiaAtaqueSierra : public AActor, public IIEstrategiasAtaquesPawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaAtaqueSierra();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AArmaAmiga* Arma1;
	class AAdapterPatern1Pawn* Jugador;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Disparar(class AArmaAmiga* Arma) override;
	virtual void MoverArma(class AArmaAmiga* Arma, float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstrategiasAtaquesPawn.h"
#include "EstrategiaAtaqueNormal.generated.h"

UCLASS()
class ADAPTERPATERN1_API AEstrategiaAtaqueNormal : public AActor, public IIEstrategiasAtaquesPawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaAtaqueNormal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	bool bCanFire = true;
	void ShotTimerExpired();
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	virtual void Disparar(class AArmaAmiga* Arma) override;
	virtual void MoverArma(class AArmaAmiga* Arma, float DeltaTime) override;

};

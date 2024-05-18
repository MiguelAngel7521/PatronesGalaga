// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaVelocidad.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ACapsulaVelocidad : public ACapsula
{
	GENERATED_BODY()
protected:
	ACapsulaVelocidad();
	FString tipoCapsula = "Velocidad";
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

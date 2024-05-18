// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CapsulasTipoFacade.h"
#include "Nivel.generated.h"

UCLASS()
class ADAPTERPATERN1_API ANivel : public ACapsulasTipoFacade
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANivel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

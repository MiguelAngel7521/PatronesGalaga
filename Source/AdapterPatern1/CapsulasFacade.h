// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CapsulasFacade.generated.h"

UCLASS()
class ADAPTERPATERN1_API ACapsulasFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsulasFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	UPROPERTY()
	class ANivel* NivelActual;

	UPROPERTY()
	TArray<class ACapsulasTipoFacade*> Nivel;

	UPROPERTY()
	TArray<FString> OrdenCapsulas;

	void NivelesCapsulas(TArray<class ACapsulasTipoFacade*> _Nivel, TArray<FString> _Orden);

	void NivelFacil();
	void NivelMedio();
	void NivelDificil();

};

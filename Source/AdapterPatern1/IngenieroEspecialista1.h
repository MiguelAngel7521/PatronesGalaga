// Fill out your copyright notice in the Description page of Project Settings
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IngenieroGeneral.h"
#include "IngenieroEspecialista1.generated.h"

UCLASS()
class ADAPTERPATERN1_API AIngenieroEspecialista1 : public AActor, public IIngenieroGeneral
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIngenieroEspecialista1();
	class AConstruirNaveEnemiga* ConstruirNave;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void SetNuevaNave(int a) override;
	void SetComponentesArmas(int d) override;
	void SetComponentesEscudos(int b) override;
	void SetComponentesProjectile(int c) override;
	void ConstruirNaveEnUbicacion(FVector Posicion, int naveTipo, int armasTipo, int escudosTipo, int proyectilesTipo) override;
	class AConstruirNaveEnemiga* GetNaveEnemiga() override;

};

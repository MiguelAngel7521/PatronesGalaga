// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IngenieroGeneral.h"
#include "IngenieroEspecialista2.generated.h"

UCLASS()
class ADAPTERPATERN1_API AIngenieroEspecialista2 : public AActor, public IIngenieroGeneral
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIngenieroEspecialista2();

	class AConstruirNaveEnemiga* ConstruirNave1;

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
	class AConstruirNaveEnemiga* GetNaveEnemiga() override;

};

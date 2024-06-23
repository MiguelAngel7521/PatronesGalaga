// Fill out your copyright notice in the Description page of Project Settings
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaBuilder.h"
#include "ConstruirNaveEnemiga.generated.h"

UCLASS()
class ADAPTERPATERN1_API AConstruirNaveEnemiga : public AActor, public INaveEnemigaBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstruirNaveEnemiga();

	int Tiempo;
	int AcEscudo;
	int J;


	class AComponenteArmas* Armas;
	class AComponenteEscudo* Escudo;
	class AProjectileEnemigo* Proyectil;
	class ANaveEnemigaCaza* NaveEnemiga; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BuildNuevaNave(FVector PosicionNave, int z) override;
	void BuildComponentesArmas(FVector PosicionBase, int w) override;
	void BuildComponentesEscudos(FVector PosicionBase, int x) override;
	void BuildComponentesProjectile(int v) override;
	void ConstruirNaveCompleta(FVector PosicionBase, int naveTipo, int armasTipo, int escudosTipo, int proyectilesTipo) ;
	

};

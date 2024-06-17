// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaBuilder.h"
#include "ProxyNaveCompuesta.generated.h"

UCLASS()
class ADAPTERPATERN1_API AProxyNaveCompuesta : public AActor, public INaveEnemigaBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProxyNaveCompuesta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	class AConstruirNaveEnemiga* construirNaveEnemiga;
	int navesEnemigasRestantes;
public:
	virtual void BuildNuevaNave(int z) override;
	void BuildComponentesArmas(int w) override;
	void BuildComponentesEscudos(int x) override;
	void NaveDestruida();
};

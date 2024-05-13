// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IngenieroGeneral.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorBuilder.generated.h"

UCLASS()
class ADAPTERPATERN1_API ADirectorBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorBuilder();

	IIngenieroGeneral* IngenieroACargo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void OrdenarIngeniero(AActor* Ingeniero);
	void ContruirNaveEnemiga();
	void ConstruirNaveEscudo();
	void ConstruirNaveBatalla();
	class AConstruirNaveEnemiga* ObtenerNave();
};

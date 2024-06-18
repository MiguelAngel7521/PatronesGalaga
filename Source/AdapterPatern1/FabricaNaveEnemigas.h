// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "FabricaNaveEnemigas.generated.h"

UCLASS()
class ADAPTERPATERN1_API AFabricaNaveEnemigas : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFabricaNaveEnemigas();
	
public:
	UFUNCTION(BlueprintCallable, Category = "Factory")
	static ANaveEnemiga* FabricarNave(FString TipoNave, int32 CantidadNaves, int32 NumeroFilas, FVector NNSpawnLocation, UObject* Outer);

private:
	static TSubclassOf<ANaveEnemiga> ArmarNave(FString TipoNave);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

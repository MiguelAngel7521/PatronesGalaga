// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SistemaPuntuacionComponente.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADAPTERPATERN1_API USistemaPuntuacionComponente : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USistemaPuntuacionComponente();

	UFUNCTION(BluePrintCallable)
	void SumarPuntaje(int Puntos, FString _nombre);
	UFUNCTION(BLuePrintCallable)
	int ObtenerPuntaje() const ;
private:
	int Puntaje;
	float MultiplicadorPuntaje;
	FString Nombre;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

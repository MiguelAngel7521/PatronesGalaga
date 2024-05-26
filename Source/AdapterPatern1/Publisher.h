// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ISuscriptor.h"
#include "Publisher.generated.h"

UCLASS()
class ADAPTERPATERN1_API APublisher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublisher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void AgregarObservador(IISuscriptor* Suscriptor);
	virtual void EliminarObservador(IISuscriptor* Suscriptor);
	virtual void Notificar(const FVector& PosicionArma, const FString& Accion);
public:
	TArray<IISuscriptor*> Suscriptores;
	FVector UltimaPosicionArma;

};

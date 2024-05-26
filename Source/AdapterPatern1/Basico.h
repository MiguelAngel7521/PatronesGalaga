// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstados.h"
#include "Basico.generated.h"

UCLASS()
class ADAPTERPATERN1_API ABasico : public AActor, public IIEstados
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasico();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	class AAdapterPatern1Pawn* Jugador;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ConArmas () override;
	void ConCamuflaje () override;
	void ConEscudos () override;
	void Invencible () override;
	void ConRadar () override;

};

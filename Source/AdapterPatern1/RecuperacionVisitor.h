// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEnemigaVisitor.h"
#include "RecuperacionVisitor.generated.h"

UCLASS()
class ADAPTERPATERN1_API ARecuperacionVisitor : public AActor, public IINaveEnemigaVisitor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARecuperacionVisitor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void VisitNaveEnemigaCaza(class ANaveEnemigaCaza* Nave) override;
	void VisitNaveEnemigaEspia(class ANaveEnemigaEspia* Nave) override;
	void VisitNaveEnemigaNodriza(class ANaveEnemigaNodriza* Nave) override;
	void VisitNaveEnemigaTransporte(class ANaveEnemigaTransporte* Nave)override;
	void VisitComponenteEscudo(class AComponenteEscudo* Componente) override;
	void VisitComponenteArmas(class AComponenteArmas* Componente) override;

};

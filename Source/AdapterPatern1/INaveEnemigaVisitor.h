// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INaveEnemigaVisitor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)

class UINaveEnemigaVisitor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADAPTERPATERN1_API IINaveEnemigaVisitor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void VisitNaveEnemigaCaza(class ANaveEnemigaCaza* Nave) = 0;
	virtual void VisitNaveEnemigaEspia(class ANaveEnemigaEspia* Nave) = 0;
	virtual void VisitNaveEnemigaNodriza(class ANaveEnemigaNodriza* Nave) = 0;
	virtual void VisitNaveEnemigaTransporte(class ANaveEnemigaTransporte* Nave) = 0;
	virtual void VisitComponenteEscudo(class AComponenteEscudo* Componente) = 0;
	virtual void VisitComponenteArmas(class AComponenteArmas* Componente) = 0;

};

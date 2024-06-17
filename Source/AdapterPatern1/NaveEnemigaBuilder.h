// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NaveEnemigaBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNaveEnemigaBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADAPTERPATERN1_API INaveEnemigaBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	virtual void BuildNuevaNave(int z) = 0;
	virtual void BuildComponentesArmas(int w) = 0;
	virtual void BuildComponentesEscudos(int x) = 0;
public:
};

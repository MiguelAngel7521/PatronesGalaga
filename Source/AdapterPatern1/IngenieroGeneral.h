// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IngenieroGeneral.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIngenieroGeneral : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADAPTERPATERN1_API IIngenieroGeneral
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetNuevaNave(int a) = 0;
	virtual void SetComponentesArmas(int d) = 0;
	virtual void SetComponentesEscudos(int b) = 0;
	virtual void SetComponentesProjectile(int c) = 0;
	virtual class AConstruirNaveEnemiga* GetNaveEnemiga() = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEstrategiasAtaquesPawn.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIEstrategiasAtaquesPawn : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADAPTERPATERN1_API IIEstrategiasAtaquesPawn
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Disparar(class AArmaAmiga* Arma) = 0;
	virtual void MoverArma(class AArmaAmiga* Arma, float DeltaTime) = 0;

};

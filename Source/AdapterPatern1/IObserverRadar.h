// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IObserverRadar.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIObserverRadar : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ADAPTERPATERN1_API IIObserverRadar
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:
	virtual void UpdatePosition(AActor* Actor) = 0;
};

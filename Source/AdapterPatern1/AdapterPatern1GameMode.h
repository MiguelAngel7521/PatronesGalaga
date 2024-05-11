// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AdapterPatern1GameMode.generated.h"

UCLASS(MinimalAPI)
class AAdapterPatern1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAdapterPatern1GameMode();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(VisibleAnywhere, Category = "Game Mode")
	class AAdapterPatern1Pawn* Jugador;
	UPROPERTY(VisibleAnywhere, Category = "Game Mode")
	class ABallAdapter* Adapter;
};




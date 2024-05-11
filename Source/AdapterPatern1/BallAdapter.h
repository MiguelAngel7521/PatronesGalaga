// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBounceBall.h"
#include "BallAdapter.generated.h"

UCLASS()
class ADAPTERPATERN1_API ABallAdapter : public AActor, public IIBounceBall
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallAdapter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(VisibleAnywhere, Category = "Ball Adapter")
	class ABall* Ball;
public:
	void Lanzar() override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponenteArmas.generated.h"

UCLASS()
class ADAPTERPATERN1_API AComponenteArmas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponenteArmas();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaArmas;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

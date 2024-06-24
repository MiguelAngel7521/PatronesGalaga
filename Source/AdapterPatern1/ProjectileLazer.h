// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileLazer.generated.h"

UCLASS()
class ADAPTERPATERN1_API AProjectileLazer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileLazer();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* lasermalla;

	// Projectile movement component


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	float varTick = 0;
	float velocidad = 0;
	float potenc = 400;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

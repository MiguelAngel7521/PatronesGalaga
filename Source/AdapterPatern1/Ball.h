// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UProjectileMovementComponent;
UCLASS()
class ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	virtual void Launch();

	bool BallLaunched;

	FVector BallVelocity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball; //Malla

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UProjectileMovementComponent* ProjectileMovement; //Movimiento del proyectil

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CollisionBall;	//Campo de colision

	float SpeedModifierOnBounce = 1.02f; //Modificador de velocidad

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); //Cuando colisiona

	UFUNCTION()
		FVector CalculateReflectionVelocity(const FVector& CurrentVelocity, const FVector& SurfaceNormal); //Calculo de la velocidad de rebote

	UFUNCTION()
		void SetVelocity(const FVector& NewVelocity); //Establecer la velocidad

	UFUNCTION()
	void EnableCollision();

	bool bCanCollide;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		UStaticMeshComponent* GetBall(); //Obtenemos la malla

	void DestroyBall(); //Destruccion de la pelota
	
};

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IBounceBall.h"
#include "AdapterPatern1Pawn.generated.h"

UCLASS(Blueprintable)
class AAdapterPatern1Pawn : public APawn, public IIBounceBall
{
	GENERATED_BODY()

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:
	AAdapterPatern1Pawn();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite )
	FVector GunOffset;
	
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;

private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
public:
	//Patron Adapter
	void Lanzar() override;
	class IIBounceBall* BounceBall;
	void SetBounceBall(AActor* _Adaptador);


	void SpawnBomba();
	// Variables para las vidas y la energía del jugador
	int32 VidasJugador = 3;
	int32 EnergiaJugador = 200;

	// Funciones para manejar el daño del enemigo y la energía del jugador
	void RecibirDanio(int32 CantidadDanio);
	void ReducirEnergia(int32 Cantidad);



private:
	// Manejador de temporizador para la vida útil de la bomba
	FTimerHandle ManejadorTemporizador_DestruirBomba;
	bool bBombaSpawned;
	TSubclassOf<class ABomba> BombaClass;


protected:
	int ContImpacto;
	
public:
	void recibirImpacto();

	int VidasRestantes = 3;
	float EnergiaRestante = 200.0f;
	

	int GetVidasRestantes() const { return VidasRestantes; }
	float GetEnergiaRestante() const { return EnergiaRestante; }
	void AumentarVida()
	{
		if (VidasRestantes > 0)
			VidasRestantes++;
	}
	// Función para reducir una vida del pawn
	void ReducirVida()
	{
		if (VidasRestantes > 0)
			VidasRestantes--;
	}
	void AumentarEnergia()
	{
		if (EnergiaRestante > 0)
			EnergiaRestante = EnergiaRestante +20;
	}

	void ReducirEnergia()
	{
		if (EnergiaRestante > 0)
			EnergiaRestante--;
		if(EnergiaRestante < 10)
			MoveSpeed = -500;
	}
	void AumentarVelocidad()
	{
		MoveSpeed += 600;
	}

	FVector posicionInicial;
	void Energia();
	FTimerHandle TimerHandle_Energia;

};


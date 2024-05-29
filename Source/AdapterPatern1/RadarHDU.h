// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "IObserverRadar.h"
#include "RadarHDU.generated.h"

/**
 * 
 */
UCLASS()
class ADAPTERPATERN1_API ARadarHDU : public AHUD   , public IIObserverRadar
{
	GENERATED_BODY()
protected:
	/*La ubicación de inicio de nuestro radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
	FVector2D RadarStartLocation = FVector2D(0.9f, 0.2f);

	/*El radio de nuestro radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
	float RadarRadius = 100.f;

	UPROPERTY(EditAnywhere, Category = Radar)
	float DegreeStep = 0.25f;

	/*El tamaño de píxel de los actores de radar dibujables*/
	UPROPERTY(EditAnywhere, Category = Radar)
	float DrawPixelSize = 5.f;

	/*Altura y radio de la esfera para nuestro raycast*/
	UPROPERTY(EditAnywhere, Category = Radar)
	float SphereHeight = 200.f;

	UPROPERTY(EditAnywhere, Category = Radar)
	float SphereRadius = 2750.f;
	
	/*La escala de distancia de los actores del radar*/
		UPROPERTY(EditAnywhere, Category = Radar)
	float RadarDistanceScale = 25.f;

	/*Convierte la ubicación de los actores dados en local (basado en nuestro personaje)*/
	FVector2D ConvertirUbicacionMundialALocal(AActor* ActorToPlace);

	/*Dibuja a los actores raycasteados en nuestro radar*/
	void DibujarRaycastedActors();



	/*Tiene una referencia a cada actora que estamos dibujando actualmente en nuestro radar*/
	TArray<AActor*> RadarActors;
private:
	/*Devuelve el centro del radar como un vector 2d*/
	FVector2D GetPosicionCentralRadar();

	/*Dibuja el radar*/
	void DibujarRadar();
	void DibujarPlayerInRadar();
	void RealizarRadarRaycast();

public:
	/*Dibuja el radar en la pantalla*/
	virtual void DrawHUD() override;

	/*Se llama cuando se actualiza el radar*/
	void UpdatePosition(AActor* Actor) override;
	
	
	


};

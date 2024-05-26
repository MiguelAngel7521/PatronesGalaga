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
	/*The start location of our radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
	FVector2D RadarStartLocation = FVector2D(0.9f, 0.2f);

	/*The radius of our radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
	float RadarRadius = 100.f;

	UPROPERTY(EditAnywhere, Category = Radar)
	float DegreeStep = 0.25f;

	/*The pixel size of the drawable radar actors*/
	UPROPERTY(EditAnywhere, Category = Radar)
	float DrawPixelSize = 5.f;

	/*Sphere height and radius for our raycast*/
	UPROPERTY(EditAnywhere, Category = Radar)
	float SphereHeight = 200.f;

	UPROPERTY(EditAnywhere, Category = Radar)
	float SphereRadius = 2750.f;
	
		/*The distance scale of the radar actors*/
		UPROPERTY(EditAnywhere, Category = Radar)
	float RadarDistanceScale = 25.f;

	/*Converts the given actors' location to local (based on our character)*/
	FVector2D ConvertWorldLocationToLocal(AActor* ActorToPlace);

	/*Draws the raycasted actors in our radar*/
	void DrawRaycastedActors();



	/*Holds a reference to every actor we are currently drawing in our radar*/
	TArray<AActor*> RadarActors;
private:
	/*Returns the center of the radar as a 2d vector*/
	FVector2D GetRadarCenterPosition();

	/*Draws the radar*/
	void DrawRadar();
	void DrawPlayerInRadar();
	void PerformRadarRaycast();

public:
	/*Draws the radar on the screen*/
	virtual void DrawHUD() override;

	/*Called when the radar is updated*/
	void UpdatePosition(AActor* Actor) override;
	
	
	


};

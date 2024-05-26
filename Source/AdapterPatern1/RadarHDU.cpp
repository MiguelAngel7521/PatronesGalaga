// Fill out your copyright notice in the Description page of Project Settings.


#include "RadarHDU.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "AdapterPatern1Pawn.h"
#include <Kismet/GameplayStatics.h>

FVector2D ARadarHDU::ConvertWorldLocationToLocal(AActor* ActorToPlace)
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (Player && ActorToPlace)
	{
		//Convert the world location to local, based on the transform of the player
		FVector ActorsLocal3dVector = Player->GetTransform().InverseTransformPosition(ActorToPlace->GetActorLocation());

		//Rotate the vector by 90 degrees counter-clockwise in order to have a valid rotation in our radar
		ActorsLocal3dVector = FRotator(0.f, -90.f, 0.f).RotateVector(ActorsLocal3dVector);

		//Apply the given distance scale
		ActorsLocal3dVector /= RadarDistanceScale;

		//Return a 2d vector based on the 3d vector we've created above
		return FVector2D(ActorsLocal3dVector);
	}
	return FVector2D(0, 0);
}

void ARadarHDU::DrawRaycastedActors()
{
	FVector2D RadarCenter = GetRadarCenterPosition();

	for (auto It : RadarActors)
	{
		FVector2D convertedLocation = ConvertWorldLocationToLocal(It);

		//We want to clamp the location of our actors in order to make sure
		//that we display them inside our radar

		//To do so, I've created the following temporary vector in order to access
		//the GetClampedToMaxSize2d function. This functions returns a clamped vector (if needed)
		//to match our max length
		FVector tempVector = FVector(convertedLocation.X, convertedLocation.Y, 0.f);

		//Subtract the pixel size in order to make the radar display more accurate
		tempVector = tempVector.GetClampedToMaxSize2D(RadarRadius - DrawPixelSize);

		//Assign the converted X and Y values to the vector we want to display
		convertedLocation.X = tempVector.X;
		convertedLocation.Y = tempVector.Y;

		DrawRect(FLinearColor::Red, RadarCenter.X + convertedLocation.X, RadarCenter.Y + convertedLocation.Y, DrawPixelSize, DrawPixelSize);
		UE_LOG(LogTemp, Warning, TEXT("Dibujando actor en el radar: %s"), *It->GetName());
	}
}

FVector2D ARadarHDU::GetRadarCenterPosition()
{
	//If the canvas is valid, return the center as a 2d vector
	return (Canvas) ? FVector2D(Canvas->SizeX * RadarStartLocation.X, Canvas->SizeY * RadarStartLocation.Y) : FVector2D(0, 0);
}

void ARadarHDU::DrawRadar()
{
	FVector2D RadarCenter = GetRadarCenterPosition();

	for (float i = 0; i < 360; i += DegreeStep)
	{
		/*Queremos dibujar un círculo para representar nuestro radar
		Para ello, calculamos el seno y el coseno de casi todos los grados
		Es imposible calcular todos y cada uno de los grados posibles porque son infinitos
		Baje el paso de grado en caso de que necesite una representación circular más precisa

		Multiplicamos nuestras coordenadas por el tamaño del radar
		Para dibujar un círculo con radio igual al que introduciremos a través del editor*/
		float fixedX = FMath::Cos(i) * RadarRadius;
		float fixedY = FMath::Sin(i) * RadarRadius;

		//Actual draw
		DrawLine(RadarCenter.X, RadarCenter.Y, RadarCenter.X + fixedX, RadarCenter.Y + fixedY, FLinearColor::Gray, 1.f);
	}
}

void ARadarHDU::DrawPlayerInRadar()
{

		FVector2D RadarCenter = GetRadarCenterPosition();
		DrawRect(FLinearColor::Blue, RadarCenter.X, RadarCenter.Y, DrawPixelSize, DrawPixelSize);
	
}

void ARadarHDU::PerformRadarRaycast()
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (Player)
	{
		TArray<FHitResult> HitResults;
		FVector EndLocation = Player->GetActorLocation();
		EndLocation.Z += SphereHeight;

		FCollisionShape CollisionShape;
		CollisionShape.ShapeType = ECollisionShape::Sphere;
		CollisionShape.SetSphere(SphereRadius);

		//Perform a the necessary sweep for actors.
		//In case you're wondering how this works, read my raycast tutorial here: http://wp.me/p6hvtS-5F
		GetWorld()->SweepMultiByChannel(HitResults, Player->GetActorLocation(), EndLocation, FQuat::Identity, ECollisionChannel::ECC_WorldDynamic, CollisionShape);

		for (auto It : HitResults)
		{
			AActor* CurrentActor = It.GetActor();
			//In case the actor contains the word "Radar" as a tag, add it to our array
			if (CurrentActor && CurrentActor->ActorHasTag("Radar")) RadarActors.Add(CurrentActor);
		}
	}
}

void ARadarHDU::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X),(Center.Y));

	// draw the crosshair

	/*FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);*/


	//----------------Radar logic----------------

	DrawRadar();

	DrawPlayerInRadar();

	PerformRadarRaycast();

	DrawRaycastedActors();

	//Empty the radar actors in case the player moves out of range,
	//by doing so, we have always a valid display in our radar
	RadarActors.Empty();
}

void ARadarHDU::UpdatePosition(AActor* Actor)
{
	if (Actor)
	{
		RadarActors.AddUnique(Actor);
		/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Actor added to radar"));*/
	}
}

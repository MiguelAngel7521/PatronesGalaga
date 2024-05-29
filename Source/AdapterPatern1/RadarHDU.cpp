// Fill out your copyright notice in the Description page of Project Settings.


#include "RadarHDU.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "AdapterPatern1Pawn.h"
#include <Kismet/GameplayStatics.h>

FVector2D ARadarHDU::ConvertirUbicacionMundialALocal(AActor* ActorToPlace)
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (Player && ActorToPlace)
	{
		//Convierte la ubicación del mundo en local, en función de la transformación de la jugadora
		FVector ActorsLocal3dVector = Player->GetTransform().InverseTransformPosition(ActorToPlace->GetActorLocation());

		//Girar el vector 90 grados en sentido contrario a las agujas del reloj para tener una rotación válida en nuestro radar
		ActorsLocal3dVector = FRotator(0.f, -90.f, 0.f).RotateVector(ActorsLocal3dVector);

		//Aplicar la escala de distancia dada
		ActorsLocal3dVector /= RadarDistanceScale;

		//Devuelve un vector 2D basado en el vector 3D que hemos creado anteriormente
		return FVector2D(ActorsLocal3dVector);
	}
	return FVector2D(0, 0);
}

void ARadarHDU::DibujarRaycastedActors()
{
	FVector2D RadarCenter = GetPosicionCentralRadar();

	for (auto It : RadarActors)
	{
		FVector2D convertedLocation = ConvertirUbicacionMundialALocal(It);

		/*Queremos fijar la ubicación de nuestros actores para asegurarnos de que
		que los exhibimos dentro de nuestro radar

		Para ello, he creado el siguiente vector temporal con el fin de acceder a
		la función GetClampedToMaxSize2d.Esta función devuelve un vector fijado(si es necesario)
		para que coincida con nuestra longitud máxima*/
		FVector tempVector = FVector(convertedLocation.X, convertedLocation.Y, 0.f);

		//Reste el tamaño de píxel para que la visualización del radar sea más precisa
		tempVector = tempVector.GetClampedToMaxSize2D(RadarRadius - DrawPixelSize);

		//Asignamos los valores X e Y convertidas al vector que queremos mostrar
		convertedLocation.X = tempVector.X;
		convertedLocation.Y = tempVector.Y;

		DrawRect(FLinearColor::Red, RadarCenter.X + convertedLocation.X, RadarCenter.Y + convertedLocation.Y, DrawPixelSize, DrawPixelSize);
		UE_LOG(LogTemp, Warning, TEXT("Dibujando actor en el radar: %s"), *It->GetName());
	}
}

FVector2D ARadarHDU::GetPosicionCentralRadar()
{
	//Si el lienzo es válido, devuelve el centro como un vector 2D
	return (Canvas) ? FVector2D(Canvas->SizeX * RadarStartLocation.X, Canvas->SizeY * RadarStartLocation.Y) : FVector2D(0, 0);
}

void ARadarHDU::DibujarRadar()
{
	FVector2D RadarCenter = GetPosicionCentralRadar();

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

void ARadarHDU::DibujarPlayerInRadar()
{

		FVector2D RadarCenter = GetPosicionCentralRadar();
		DrawRect(FLinearColor::Blue, RadarCenter.X, RadarCenter.Y, DrawPixelSize, DrawPixelSize);
	
}

void ARadarHDU::RealizarRadarRaycast()
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

		//Realizar un barrido necesario para los actores.
		GetWorld()->SweepMultiByChannel(HitResults, Player->GetActorLocation(), EndLocation, FQuat::Identity, ECollisionChannel::ECC_WorldDynamic, CollisionShape);

		for (auto It : HitResults)
		{
			AActor* CurrentActor = It.GetActor();
			//En caso de que el actor contenga la palabra "Radar" como etiqueta, agréguela a nuestra matriz
			if (CurrentActor && CurrentActor->ActorHasTag("Radar")) RadarActors.Add(CurrentActor);
		}
	}
}

void ARadarHDU::DrawHUD()
{
	Super::DrawHUD();

	//  Draw very simple crosshair

	// encontrar el centro del lienzo
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// desplazado por la mitad de las dimensiones de la textura para que el centro de la textura se alinee con el centro del lienzo
	const FVector2D CrosshairDrawPosition((Center.X),(Center.Y));

	// Dibuja el punto de mira

	/*FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);*/


	//----------------Radar logic----------------

	DibujarRadar();

	DibujarPlayerInRadar();

	RealizarRadarRaycast();

	DibujarRaycastedActors();

	/*Vaciar los actores del radar en caso de que el jugador se mueva fuera del alcance,
	Al hacerlo, siempre tenemos una pantalla válida en nuestro radar*/
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

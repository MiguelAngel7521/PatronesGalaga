// Fill out your copyright notice in the Description page of Project Settings.


#include "SistemaPuntuacionComponente.h"

// Sets default values for this component's properties
USistemaPuntuacionComponente::USistemaPuntuacionComponente()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Puntaje = 0;
	MultiplicadorPuntaje = 1.0f;

	
}

void USistemaPuntuacionComponente::SumarPuntaje(int Puntos, FString _nombre)
{
	int PuntosTotales = Puntos * MultiplicadorPuntaje;
	Puntaje += PuntosTotales;
	FText Message = FText::Format(NSLOCTEXT("YourNamespace", "ScoreUpdateMessage", "¡{0} destruida! Puntaje: {1}"), FText::FromString(_nombre), FText::AsNumber(Puntaje));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Message.ToString());
}

int USistemaPuntuacionComponente::ObtenerPuntaje() const
{
	return Puntaje;
}	


// Called when the game starts
void USistemaPuntuacionComponente::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USistemaPuntuacionComponente::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


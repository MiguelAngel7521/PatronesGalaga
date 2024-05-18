// Fill out your copyright notice in the Description page of Project Settings.


#include "Puntaje.h"
#include "NaveEnemigaCaza.h"


// Sets default values
APuntaje::APuntaje()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	score = 0.0f;

}

// Called when the game starts or when spawned
void APuntaje::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuntaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuntaje::CalcularPuntaje(float Puntaje)
{
	
	score += Puntaje;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Puntaje: %f"), Puntaje));
}


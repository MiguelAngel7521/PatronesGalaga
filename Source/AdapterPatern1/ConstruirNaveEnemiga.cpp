// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstruirNaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "ComponenteArmas.h"
#include "ComponenteEscudo.h"
#include "ProjectileEnemigo.h"
#include "ProjectileLazer.h"


// Sets default values
AConstruirNaveEnemiga::AConstruirNaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Tiempo = 0;
	AcEscudo = 1; 
}

// Called when the game starts or when spawned
void AConstruirNaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstruirNaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Tiempo++;
		if (Tiempo % 100 == 0)
		{
			BuildComponentesProjectile(J);
		}

}

void AConstruirNaveEnemiga::BuildNuevaNave(FVector PosicionNave, int z)
{
	FRotator RotacionNave = FRotator(0.0f, 180.0f, 0.0f);

	NaveEnemiga = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass());
	NaveEnemiga->SetActorLocation(PosicionNave);
	NaveEnemiga->SetActorRotation(RotacionNave);
}

void AConstruirNaveEnemiga::BuildComponentesArmas(FVector PosicionBase, int w)
{
	FVector PosArmas = PosicionBase + FVector(-200.0f, -450.0f, 0.0f);
	FRotator RotArmas = FRotator(0.0f, 180.0f, 0.0f);

	switch (w)
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			Armas = GetWorld()->SpawnActor<AComponenteArmas>(AComponenteArmas::StaticClass());
			Armas->SetActorLocation(PosArmas);
			Armas->SetActorRotation(RotArmas);
			PosArmas.Y += 400.0f;
			//if (Armas)
			//{
			//	// Adjuntar el componente Armas a la malla de la nave enemiga
			//	Armas->AttachToComponent(NaveEnemiga->mallaNaveEnemiga, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			//}
			//else
			//{
			//	UE_LOG(LogTemp, Warning, TEXT("Fallo al spawnear Armas"));
			//}
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++)
		{
			Armas = GetWorld()->SpawnActor<AComponenteArmas>(AComponenteArmas::StaticClass());
			Armas->SetActorLocation(PosArmas);
			Armas->SetActorRotation(RotArmas);
			PosArmas.Y += (i == 1) ? 720.0f : 110.0f;
			// Asegurar que NaveEnemiga tenga un componente Armas antes de intentar acceder a él
			//if (Armas)
			//{
			//	// Adjuntar el componente Armas a la malla de la nave enemiga
			//	Armas->AttachToComponent(NaveEnemiga->mallaNaveEnemiga, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			//}
			//else
			//{
			//	GEngine -> AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fallo al spawnear Armas"));
			//}
		}
		break;
	default:
		break;
	}
}

void AConstruirNaveEnemiga::BuildComponentesEscudos(FVector PosicionBase, int x)
{
	FVector PosEscudo = PosicionBase + FVector(-200.0f, -170.0f, 0.0f);
	FRotator RotEscudo = FRotator(0.0f, 180.0f, 0.0f);

	switch (x)
	{
	case 1:
		Escudo = GetWorld()->SpawnActor<AComponenteEscudo>(AComponenteEscudo::StaticClass());
		Escudo->SetActorLocation(PosEscudo);
		Escudo->SetActorRotation(RotEscudo);
		//if (Escudo)
		//{
		//	// Adjuntar el componente Escudo a la malla de la nave enemiga
		//	Escudo->AttachToComponent(NaveEnemiga->mallaNaveEnemiga, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		//}
		//else
		//{
		//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fallo al spawnear Escudo"));	
		//}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
		{
			Escudo = GetWorld()->SpawnActor<AComponenteEscudo>(AComponenteEscudo::StaticClass());
			Escudo->SetActorLocation(PosEscudo);	
			Escudo->SetActorRotation(RotEscudo);
			PosEscudo.Y += 200.0f;
			//if (Escudo)
			//{
			//	// Adjuntar el componente Escudo a la malla de la nave enemiga
			//	Escudo->AttachToComponent(NaveEnemiga->mallaNaveEnemiga, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			//}
			//else
			//{
			//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fallo al spawnear Escudo"));
			//}
		}
		break;
	default:
		break;
	}
}

void AConstruirNaveEnemiga::BuildComponentesProjectile(int v)
{
	J = v;

	if (!NaveEnemiga)
	{
		UE_LOG(LogTemp, Warning, TEXT("NaveEnemiga no está inicializada."));
		return;
	}

	FVector PosNaveEnemiga = NaveEnemiga->GetActorLocation();
	FVector PosProyectil = PosNaveEnemiga + FVector(-200.0f, 0.0f, 0.0f); // Siempre en X = 200 respecto a la nave
	FRotator RotProyectil = FRotator(0.0f, 180.0f, 0.0f);

	switch (v)
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			AProjectileLazer* Proyectil2  = GetWorld()->SpawnActor<AProjectileLazer>(AProjectileLazer::StaticClass());
			Proyectil2->SetActorLocation(PosProyectil);
			Proyectil2->SetActorRotation(RotProyectil);
			PosProyectil.Y += 200.0f;
		}
		break;
	case 2:
		// Aquí podrías manejar otro tipo de proyectil si fuera necesario
		break;
	case 3:
		for (int i = 0; i < 4; i++)
		{
			AProjectileLazer* Proyectil1 = GetWorld()->SpawnActor<AProjectileLazer>(AProjectileLazer::StaticClass());
			Proyectil1->SetActorLocation(PosProyectil);
			Proyectil1->SetActorRotation(RotProyectil);
			if (i == 1)
			{
				PosProyectil.Y += 220.0f;
			}
			else
			{
				PosProyectil.Y += 110.0f;
			}
		}
		break;
	default:
		break;
	}
}

void AConstruirNaveEnemiga::ConstruirNaveCompleta(FVector PosicionBase, int naveTipo, int armasTipo, int escudosTipo, int proyectilesTipo)
{
	BuildNuevaNave(PosicionBase, naveTipo);
	BuildComponentesArmas(PosicionBase, armasTipo);
	BuildComponentesEscudos(PosicionBase, escudosTipo);
	BuildComponentesProjectile(proyectilesTipo);
}




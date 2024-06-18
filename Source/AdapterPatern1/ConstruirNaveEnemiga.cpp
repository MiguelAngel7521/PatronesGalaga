// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstruirNaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "ComponenteArmas.h"
#include "ComponenteEscudo.h"
#include "ProjectileEnemigo.h"


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
	/*J = v;

	FVector PosProyectil = FVector(-200.0f, 430.0f, 300.0f);
	FRotator RotProyectil = FRotator(0.0f, 180.0f, 0.0f);
	FVector PosProyectil1 = FVector(-200.0f, 430.0f, 300.0f);

	switch (v)
	{
	case 1:

		

		for (int i = 0; i < 2; i++)
		{
			Proyectil = GetWorld()->SpawnActor<AProjectileEnemigo>(AProjectileEnemigo::StaticClass());
			Proyectil->SetActorLocation(PosProyectil);
			Proyectil->SetActorRotation(RotProyectil);
			PosProyectil.Y = PosProyectil.Y + 200.0f;
		}

		break;
	case 2:

		break;
	case 3:

		

		for (int i = 0; i < 4; i++)
		{
			Proyectil = GetWorld()->SpawnActor<AProjectileEnemigo>(AProjectileEnemigo::StaticClass());
			Proyectil->SetActorLocation(PosProyectil1);
			Proyectil->SetActorRotation(RotProyectil);
			if (i == 1)
			{
				PosProyectil1.Y = PosProyectil1.Y + 220.0f;
			}
			else
			{
				PosProyectil1.Y = PosProyectil1.Y + 110.0f;
			}
		}

		break;
	default:
		break;
	}*/
}

void AConstruirNaveEnemiga::ConstruirNaveCompleta(FVector PosicionBase, int naveTipo, int armasTipo, int escudosTipo, int proyectilesTipo)
{
	BuildNuevaNave(PosicionBase, naveTipo);
	BuildComponentesArmas(PosicionBase, armasTipo);
	BuildComponentesEscudos(PosicionBase, escudosTipo);
	BuildComponentesProjectile(proyectilesTipo);
}




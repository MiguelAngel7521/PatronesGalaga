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

void AConstruirNaveEnemiga::BuildNuevaNave(int z)
{
	FVector PosicionNave = FVector(90.0f, 0.0f, 250.0f);
	FRotator RotacionNave = FRotator(0.0f, 180.0f, 0.0f);

	NaveEnemiga = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass());
	NaveEnemiga->SetActorLocation(PosicionNave);
	NaveEnemiga->SetActorRotation(RotacionNave);
}

void AConstruirNaveEnemiga::BuildComponentesArmas(int w)
{
	FVector PosArmas = FVector(-25.0f, -90.0f, 250.0f);
	FRotator RotArmas = FRotator(100.0f, 0.0f, 0.0f);

	FVector PosArmas1 = FVector(-25.0f, 440.0f, 250.0f);
	FRotator RotArmas1 = FRotator(100.0f, 0.0f, 0.0f);
	switch (w)
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			Armas = GetWorld()->SpawnActor<AComponenteArmas>(AComponenteArmas::StaticClass());
			Armas->SetActorLocation(PosArmas);
			Armas->SetActorRotation(RotArmas);

			PosArmas.Y = PosArmas.Y + 200.0f;
		}
		break;
		case 2:
			
			break;
		case 3:
			for (int i = 0; i < 4; i++)
			{
			Armas = GetWorld()->SpawnActor<AComponenteArmas>(AComponenteArmas::StaticClass());
			Armas->SetActorRotation(RotArmas1);
			Armas->SetActorLocation(PosArmas1);
			if (i == 1)
			{
				PosArmas1.Y = PosArmas1.Y + 220.0f;
			}
			else
			{
				PosArmas1.Y = PosArmas1.Y + 110.0f;
			}
			}
			break;
	default:
		break;
	}
}

void AConstruirNaveEnemiga::BuildComponentesEscudos(int x)
{
	FVector PosEscudo = FVector(-150.0f, 0.0f, 250.0f);
	FRotator RotEscudo = FRotator(0.0f, 90.0f, 0.0f);
	FVector PosEscudo1 = FVector(-150.0f, -700.0f, 250.0f);

	switch (x)
	{
	case 1:

		Escudo = GetWorld()->SpawnActor<AComponenteEscudo>(AComponenteEscudo::StaticClass());
		/*FVector PosEscudo = FVector(-150.0f, 0.0f, 350.0f);*/
		Escudo->SetActorLocation(PosEscudo);
		Escudo->SetActorRotation(RotEscudo);

		break;
	case 2:

		for (int i = 0; i < 3; i++)
		{
			Escudo = GetWorld()->SpawnActor<AComponenteEscudo>(AComponenteEscudo::StaticClass());
			/*FVector PosEscudo1 = FVector(-150.0f, 700.0f, 350.0f);*/
			Escudo->SetActorLocation(PosEscudo1);
			Escudo->SetActorRotation(RotEscudo);
			PosEscudo1.Y = PosEscudo1.Y + 200.0f;
		}

		break;
	case 3:

		break;
	default:
		break;
	}
}

void AConstruirNaveEnemiga::BuildComponentesProjectile(int v)
{
	J = v;

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
	}
}




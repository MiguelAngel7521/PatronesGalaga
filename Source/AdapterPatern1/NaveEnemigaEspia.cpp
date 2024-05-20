// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"
#include "AdapterPatern1Projectile.h"

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialBall(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/NavesEnemigas.NavesEnemigas'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);;
	mallaNaveEnemiga->SetMaterial(0, MaterialBall.Object);
	mallaNaveEnemiga->BodyInstance.SetCollisionProfileName("NaveEnemiga");
	mallaNaveEnemiga->OnComponentHit.AddDynamic(this, &ANaveEnemigaEspia::OnHit);


	escudo = 100;
	Sigilo = 100;
	consumo_de_energia = 10;
	Armamento = 10;
}

void ANaveEnemigaEspia::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();
	float NuevaX = FMath::RandRange(-1000, 1000) * DeltaTime;
	float NuevaY = FMath::RandRange(-1000, 1000) * DeltaTime;
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);
	NuevaPosicion.X = NuevaPosicion.X + Sigilo * DeltaTime;
	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaEspia::ActivarSigilo()
{
	Sigilo = Sigilo - consumo_de_energia;
}

void ANaveEnemigaEspia::DesactivarSigilo()
{
	Sigilo = Sigilo + consumo_de_energia;
}

void ANaveEnemigaEspia::RecopilarInformacion()
{
}

void ANaveEnemigaEspia::InterceptarComunicaciones()
{
}

//void ANaveEnemigaEspia::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	if (OtherActor && OtherActor->IsA(AAdapterPatern1Projectile::StaticClass()))
//	{
//		AAdapterPatern1Projectile* Projectile = Cast<AAdapterPatern1Projectile>(OtherActor);
//		if (Projectile)
//		{
//			// Destruye el proyectil
//			Projectile->Destroy();
//
//			Destroy();
//
//			if (SharedSistemaPuntuacionComponente)
//			{
//				SharedSistemaPuntuacionComponente->SumarPuntaje(10.0f, nombre);
//			}
//			else
//			{
//				UE_LOG(LogTemp, Warning, TEXT("SistemaPuntuacionComponente is null!"));
//			}
//		}
//	}
//}



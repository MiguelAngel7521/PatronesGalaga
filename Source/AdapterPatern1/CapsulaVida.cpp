// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida.h"
#include "AdapterPatern1Pawn.h"

ACapsulaVida::ACapsulaVida()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/Capsulas.Capsulas'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialCapsula(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/CapVida.CapVida'"));
	mallaCapsula->SetStaticMesh(Mesh.Object);;
	mallaCapsula->SetMaterial(0, MaterialCapsula.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaVida::OnHit);
}

void ACapsulaVida::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AAdapterPatern1Pawn* Pawn = Cast<AAdapterPatern1Pawn>(OtherActor);
	if (Pawn)
	{
		Pawn->AumentarVida();

		// Mostrar un mensaje informando al jugador sobre la pérdida de vida
		FString Message = FString::Printf(TEXT("Vidas restantes: %d "), Pawn->GetVidasRestantes());
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message);
		//PawnScore += ScorePorEnemigo;


		
		Destroy();
	}
	
	
}

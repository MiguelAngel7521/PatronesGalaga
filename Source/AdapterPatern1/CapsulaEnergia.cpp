// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia.h"
#include "AdapterPatern1Pawn.h"

ACapsulaEnergia::ACapsulaEnergia()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/Capsulas.Capsulas'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialCapsula(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/CapsulaEnergia.CapsulaEnergia'"));
	mallaCapsula->SetStaticMesh(Mesh.Object);;
	mallaCapsula->SetMaterial(0, MaterialCapsula.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaEnergia::OnHit);
}

void ACapsulaEnergia::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AAdapterPatern1Pawn* Pawn = Cast<AAdapterPatern1Pawn>(OtherActor);
	if (Pawn)
	{
		Pawn->AumentarEnergia();
		FString Message = FString::Printf(TEXT("Energia Restante: %d "), Pawn->ObtenerEnergiaRestante());
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, Message);
		Destroy();
	}
}

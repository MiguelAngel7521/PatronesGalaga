// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVelocidad.h"
#include "AdapterPatern1Pawn.h"


ACapsulaVelocidad::ACapsulaVelocidad()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Geometry/Meshes/Capsulas.Capsulas'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialCapsula(TEXT("MaterialInstanceConstant'/Game/TwinStick/Meshes/Capsulas.Capsulas'"));
	mallaCapsula->SetStaticMesh(Mesh.Object);;
	mallaCapsula->SetMaterial(0, MaterialCapsula.Object);
	mallaCapsula->BodyInstance.SetCollisionProfileName("Capsule");
	mallaCapsula->OnComponentHit.AddDynamic(this, &ACapsulaVelocidad::OnHit);
}

void ACapsulaVelocidad::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AAdapterPatern1Pawn* Pawn = Cast<AAdapterPatern1Pawn>(OtherActor);
	if (Pawn)
	{
		Pawn->AumentarVelocidad();
		FString Message = FString::Printf(TEXT("Velocidad Aumentada "));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Black, Message);
		Destroy();
	}
}

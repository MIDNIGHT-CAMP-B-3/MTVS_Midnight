// Fill out your copyright notice in the Description page of Project Settings.


#include "HeartActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHeartActor::AHeartActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Heart1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Heart1comp"));
	Heart2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hear21comp"));
	Heart2->SetRelativeLocation(FVector(190,0,0));
	Heart3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hear31comp"));
	Heart3->SetRelativeLocation(FVector(380, 0, 0));
}

// Called when the game starts or when spawned
void AHeartActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeartActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


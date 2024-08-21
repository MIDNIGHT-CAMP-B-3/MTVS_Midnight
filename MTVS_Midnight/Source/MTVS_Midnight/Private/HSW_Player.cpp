// Fill out your copyright notice in the Description page of Project Settings.


#include "HSW_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AHSW_Player::AHSW_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 스프링암을 생성해서 루트에 붙이고 싶다.
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	SpringArmComp->SetRelativeLocation(FVector(130.f, 0.f, 120.f));
	SpringArmComp->SetRelativeRotation(FRotator(-10.f, 180.f, 0.f));

	SpringArmComp->TargetArmLength = 0;

	// 카메라 생성해서 스프링암에 붙이고싶다.
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AHSW_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHSW_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCanLookBack == true)
	{
		GetMesh()->SetRelativeRotation(FMath::Lerp(GetMesh()->GetRelativeRotation(), LookBackRotation, 0.1f));
		//SetActorRotation(FMath::Lerp(GetActorRotation(), LookBackRotation, 0.1f));
	}
	else
	{
		GetMesh()->SetRelativeRotation(FMath::Lerp(GetMesh()->GetRelativeRotation(), DefaultRotation, 0.1f));
		//SetActorRotation(FMath::Lerp(GetActorRotation(), DefaultRotation, 0.1f));
	}
}

// Called to bind functionality to input
void AHSW_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

 	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Pressed, this, &AHSW_Player::onMyActionLookBack);
 	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Released, this, &AHSW_Player::onMyActionLookBack);

//	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Pressed, this, & AHSW_Player::TurnBack);
//	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Released, this, &AHSW_Player::LookForward);
}

void AHSW_Player::onMyActionLookBack()
{
	bCanLookBack = !bCanLookBack;
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("onMyActionLookBack"));
}

void AHSW_Player::TurnBack()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("TurnBack"));
	FRotator newRotation = FRotator(0.f, 90.f, 0.f);
	GetMesh()->SetRelativeRotation(newRotation);
//	SetActorRotation(newRotation);


}

void AHSW_Player::LookForward()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("LookForward"));
	FRotator defaultRotation = FRotator(0.f, -90.f, 0.f);
	GetMesh()->SetRelativeRotation(defaultRotation);
//	SetActorRotation(defaultRotation);
}


#include "AIChildCharacter.h"
// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFramework/CharacterMovementComponent.h"
#include "AIChildCharacterAnimInstance.h"
#include "HSW_Player.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AAIChildCharacter::AAIChildCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//mesh 에서 퀸을 로드해서 넣고 싶다.
	ConstructorHelpers::FObjectFinder<USkeletalMesh> Finder(TEXT("/Script/Engine.SkeletalMesh'/Game/LSJ/Character/Walking__8_.Walking__8_'"));
	if (Finder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(Finder.Object);
		GetMesh()->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -100.f), FRotator(0, -90.f, 0));
		GetMesh()->SetRelativeScale3D(FVector(.8, 0.8, 0.8));
	}


	ConstructorHelpers::FClassFinder<UAnimInstance> animFinder(TEXT("/Script/Engine.AnimBlueprint'/Game/LSJ/ABP_AIChildRed.ABP_AIChildRed_C'"));
	if (animFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animFinder.Class);
	}

	//회전 가능하게
	GetCharacterMovement()->bOrientRotationToMovement = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AAIChildCharacter::BeginPlay()
{
	Super::BeginPlay();
	//플레이어 찾기
	player = Cast<AHSW_Player>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	if (player)
		bCanLookBack = player->bCanLookBack;
	
	//애님 인스턴스 만들기
	anim = Cast<UAIChildCharacterAnimInstance>(GetMesh()->GetAnimInstance());

	startLocation = GetActorLocation();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AAIChildCharacter::SetMoveState, 3, false);
	int32 randNum = FMath::RandRange(3, 10);
	moveSpeed = randNum;
	float randFloat = FMath::RandRange(0.1, 1.0);
	randomScaleSpeed= randFloat;

	int32 randNumWalkStyle = FMath::RandRange(0, 1);
	randNumWalkStyle?walkStyle1=true:walkStyle2=true;
}

// Called every frame
void AAIChildCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FString myState = UEnum::GetValueAsString(State);
	DrawDebugString(GetWorld(), GetActorLocation(), myState, nullptr, FColor::Yellow, 0);
	switch (State)
	{
	case EAIChildCharacterState::IDLE:
		TickIdle(DeltaTime);
		break;
	case EAIChildCharacterState::STOP:
		TickStop(DeltaTime);
		break;
	case EAIChildCharacterState::MOVE:
		TickMove(DeltaTime);
		break;
	case EAIChildCharacterState::Complete:
		TickComplete(DeltaTime);
		break;
	case EAIChildCharacterState::Die:
		TickDie(DeltaTime);
		break;
	}

	if (player && bGameStart)
	{
		if (bCanLookBack != player->bCanLookBack)
		{
			bCanLookBack = player->bCanLookBack;
			if (bCanLookBack) //player look back
			{
				//30% Move And Only 1 child
				//Select Only One
				// //spawner select One
				// //player->bCanLookBack == 0 
				// //bCanMove = true -> Select one move
				int32 randNum = FMath::RandRange(1, 10);
				if (bCanMove && randNum <= 5)
				{
					//1초 후에 멈추기
					FTimerHandle stopTimerHandle;
					float randNumFloat = FMath::RandRange(1.0f, 1.5f);
					GetWorld()->GetTimerManager().SetTimer(stopTimerHandle, this, &AAIChildCharacter::SetStopState, randNumFloat, false);
				}
				else
				{
					SetStopState();
				}
			}
			else
			{
				SetMoveState();
			}
		}
	}
}

// Called to bind functionality to input
void AAIChildCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIChildCharacter::TickStop(const float& DeltaTime)
{

}

void AAIChildCharacter::TickMove(const float& DeltaTime)
{
	//목적지를 향해서 이동하고 싶다.
	FVector direction = GetActorLocation() + GetActorForwardVector()* 10000.0f - GetActorLocation();
	FVector goalDirection = startLocation + GetActorForwardVector() * goalDistance - GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%f"), goalDirection.Length());
	//목적 거리까지 오면 Complete 상태로 전환
	if (goalDirection.Length() <= 10)
	{
		
		SetState(EAIChildCharacterState::Complete);
		return;
	}
	direction.Normalize();
	UE_LOG(LogTemp, Error, TEXT("%f"), moveSpeed);
	AddMovementInput(direction * 0.5, randomScaleSpeed);
	//EPathFollowingRequestResult::Type result = enemyAIController->MoveToLocation(player->GetActorLocation());
}
void AAIChildCharacter::SetMoveState()
{
	bGameStart = true;
	GetMesh()->bPauseAnims = false;
	SetState(EAIChildCharacterState::MOVE);
}
void AAIChildCharacter::SetStopState()
{
	GetMesh()->bPauseAnims = true;
	SetState(EAIChildCharacterState::STOP);
}
void AAIChildCharacter::SetState(EAIChildCharacterState NextState)
{
	EAIChildCharacterState prevState = State;
	State = NextState;
	//currentTime = 0;
	//anim->EnemyState = NextState;
	//switch (prevState)
	//{
	//case EEnemyState::IDLE:
	//	break;
	//case EEnemyState::MOVE:
	//	break;
	//case EEnemyState::ATTACK:
	//	break;
	//case EEnemyState::DAMAGE:
	//	break;
	//case EEnemyState::DIE:
	//	break;
	//}
}

void AAIChildCharacter::TickComplete(const float& DeltaTime)
{

}

void AAIChildCharacter::TickDie(const float& DeltaTime)
{
}
void AAIChildCharacter::TickIdle(const float& DeltaTime)
{
}


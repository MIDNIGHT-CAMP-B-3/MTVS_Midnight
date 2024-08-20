#include "AIChildCharacter.h"
// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFramework/CharacterMovementComponent.h"
#include "AIChildCharacterAnimInstance.h"
// Sets default values
AAIChildCharacter::AAIChildCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//mesh ���� ���� �ε��ؼ� �ְ� �ʹ�.
	ConstructorHelpers::FObjectFinder<USkeletalMesh> Finder(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	if (Finder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(Finder.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90.f), FRotator(0, -90.f, 0));
		GetMesh()->SetRelativeScale3D(FVector(.8, 0.8, 0.8));
	}


	ConstructorHelpers::FClassFinder<UAnimInstance> animFinder(TEXT("/Script/Engine.AnimBlueprint'/Game/LSJ/AB_AIChildCharacter.AB_AIChildCharacter_C'"));
	if (animFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animFinder.Class);
	}

	//ȸ�� �����ϰ�
	GetCharacterMovement()->bOrientRotationToMovement = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AAIChildCharacter::BeginPlay()
{
	Super::BeginPlay();
	//�÷��̾� ã��
	
	//�ִ� �ν��Ͻ� �����
	anim = Cast<UAIChildCharacterAnimInstance>(GetMesh()->GetAnimInstance());

	startLocation = GetActorLocation();

	FTimerHandle TimerHandle;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AAIChildCharacter::SetMoveState, 3, false);
}

// Called every frame
void AAIChildCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FString myState = UEnum::GetValueAsString(State);
	DrawDebugString(GetWorld(), GetActorLocation(), myState, nullptr, FColor::Yellow, 0);
	switch (State)
	{
	case EAIChildCharacterState::STOP:
		TickStop(DeltaTime);
		break;
	case EAIChildCharacterState::MOVE:
		TickMove(DeltaTime);
		break;
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
	//�������� ���ؼ� �̵��ϰ� �ʹ�.
	//���� ���� �������͟� �Ÿ��� ���ݰ��� �Ÿ���� 
	//���ݻ��·� �����ϰ� �ʹ�.
	FVector direction = GetActorLocation() + GetActorForwardVector()* 10000.0f - GetActorLocation();
	//
	FVector goalDirection = startLocation + GetActorForwardVector() * goalDistance - GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("%f"), goalDirection.Length());
	if (goalDirection.Length() <= 10)
	{
		
		SetState(EAIChildCharacterState::Complete);
		return;
	}
	direction.Normalize();
	AddMovementInput(direction * 10 , 1.0f);
	//EPathFollowingRequestResult::Type result = enemyAIController->MoveToLocation(player->GetActorLocation());
}
void AAIChildCharacter::SetMoveState()
{
	SetState(EAIChildCharacterState::MOVE);
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


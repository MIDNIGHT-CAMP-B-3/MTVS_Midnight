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

	/*int32 randNumUSkeletalMesh = FMath::RandRange(1, 3);
	if (randNumUSkeletalMesh == 1)
	{
		ConstructorHelpers::FObjectFinder<USkeletalMesh> Finder1(TEXT("/Script/Engine.SkeletalMesh'/Game/LSJ/Character/npc1/Crouched_Walking__1_.Crouched_Walking__1_'"));
		if (Finder1.Succeeded())
		{
			GetMesh()->SetSkeletalMesh(Finder1.Object);
			GetMesh()->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
			GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -100.f), FRotator(0, -90.f, 0));
			GetMesh()->SetRelativeScale3D(FVector(.8, 0.8, 0.8));
		}
	}
	else if (randNumUSkeletalMesh == 2)
	{
		ConstructorHelpers::FObjectFinder<USkeletalMesh> Finder2(TEXT("/Script/Engine.SkeletalMesh'/Game/LSJ/Character/npc2/Walking__7_.Walking__7_'"));
		if (Finder2.Succeeded())
		{
			GetMesh()->SetSkeletalMesh(Finder2.Object);
			GetMesh()->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
			GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -100.f), FRotator(0, -90.f, 0));
			GetMesh()->SetRelativeScale3D(FVector(.8, 0.8, 0.8));
		}

	}
	else if (randNumUSkeletalMesh == 3)
	{

		ConstructorHelpers::FObjectFinder<USkeletalMesh> Finder3(TEXT("/Script/Engine.SkeletalMesh'/Game/LSJ/Character/Walking__8_.Walking__8_'"));
		if (Finder3.Succeeded())
		{
			GetMesh()->SetSkeletalMesh(Finder3.Object);
			GetMesh()->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
			GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -100.f), FRotator(0, -90.f, 0));
			GetMesh()->SetRelativeScale3D(FVector(.8, 0.8, 0.8));
		}
	}*/
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh> Finder(TEXT("/Script/Engine.SkeletalMesh'/Game/Mingi/Characters/Npcs/FIXEDRED/SKM_Red.SKM_Red'"));
	if (Finder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(Finder.Object);
		GetMesh()->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -100.f), FRotator(0, -90.f, 0));
		GetMesh()->SetRelativeScale3D(FVector(.8, 0.8, 0.8));
	}

	ConstructorHelpers::FClassFinder<UAnimInstance> animFinder(TEXT("/Script/Engine.AnimBlueprint'/Game/LSJ/ABP_Red.ABP_Red_C'"));
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
	player = Cast<AHSW_Player>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	if (player)
		bCanLookBack = player->bCanLookBack;
	
	//�ִ� �ν��Ͻ� �����
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

	ApplySkeletalMesh();
}

void AAIChildCharacter::ApplySkeletalMesh()
{
	if (NewSkeletalMesh && NewSkeletalMesh2 && NewSkeletalMesh3)
	{
		TArray<AActor*> EnemyActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIChildCharacter::StaticClass(), EnemyActors);

		// �� ĳ������ �� ��ȯ
		if (EnemyActors.Num() == 1)
		{
			// �޽ø� ����
			GetMesh()->SetSkeletalMesh(NewSkeletalMesh);
			GetMesh()->SetAnimInstanceClass(AnimInstanceClass1);
			anim = Cast<UAIChildCharacterAnimInstance>(GetMesh()->GetAnimInstance());
		}else
		if (EnemyActors.Num() == 2)
		{
			// �޽ø� ����
			GetMesh()->SetSkeletalMesh(NewSkeletalMesh2);
			GetMesh()->SetAnimInstanceClass(AnimInstanceClass2);
			anim = Cast<UAIChildCharacterAnimInstance>(GetMesh()->GetAnimInstance());
		}else
		if (EnemyActors.Num() == 3)
		{
			// �޽ø� ����
			GetMesh()->SetSkeletalMesh(NewSkeletalMesh3);
			GetMesh()->SetAnimInstanceClass(AnimInstanceClass3);
			anim = Cast<UAIChildCharacterAnimInstance>(GetMesh()->GetAnimInstance());
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NewSkeletalMesh is not set!"));
	}
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
	case EAIChildCharacterState::Selected:
		TickSelected(DeltaTime);
		break;
	case EAIChildCharacterState::Mission:
		TickMission(DeltaTime);
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
					//1�� �Ŀ� ���߱�
					
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

void AAIChildCharacter::SetCompleteState()
{
	SetState(EAIChildCharacterState::Complete);
}

void AAIChildCharacter::TouchEnemy()
{
	if (bCanMove)
	{
		SetState(EAIChildCharacterState::Selected);
		bCanMove = false;
	}
	else
	{
		//�÷��̾� hp �ޱ�
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Character HP --"));
	}
}

void AAIChildCharacter::TickStop(const float& DeltaTime)
{

}

void AAIChildCharacter::TickMove(const float& DeltaTime)
{
	//�������� ���ؼ� �̵��ϰ� �ʹ�.
	FVector direction = GetActorLocation() + GetActorForwardVector()* 10000.0f - GetActorLocation();
	FVector goalDirection = startLocation + GetActorForwardVector() * goalDistance - GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%f"), goalDirection.Length());
	//���� �Ÿ����� ���� Complete ���·� ��ȯ
	if (goalDirection.Length() <= 10)
	{
		SetState(EAIChildCharacterState::Complete);
		return;
	}
	direction.Normalize();

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
void AAIChildCharacter::SetMissionState()
{
	SetState(EAIChildCharacterState::Mission);
}
void AAIChildCharacter::SetState(EAIChildCharacterState NextState)
{
	EAIChildCharacterState prevState = State;
	State = NextState;
	//currentTime = 0;
	//anim->EnemyState = NextState;
	FVector CurrentLocation;
	switch (State)
	{
	case EAIChildCharacterState::IDLE:
		break;
	case EAIChildCharacterState::MOVE:
		break;
	case EAIChildCharacterState::STOP:
		GetMesh()->bPauseAnims = true;
		break;
	case EAIChildCharacterState::Complete:
		GetCharacterMovement()->GravityScale = 0.0f;
		anim->bSelected = true;
		CurrentLocation = GetActorLocation();
		CurrentLocation.Z += 400.0f;
		SetActorLocation(CurrentLocation);

		StartLocation = GetActorLocation();
		EndLocation = player->GetActorLocation() + GetActorForwardVector() * -400.f;
		EndLocation.Z = GetActorLocation().Z;

		break;
	case EAIChildCharacterState::Selected:
		//���� �ִϸ��̼� ����
		GetWorld()->GetTimerManager().ClearTimer(stopTimerHandle);
		GetMesh()->bPauseAnims = false;
		anim->Montage_Play(anim->surprisedMontage, 2.0f);
		break;
	case EAIChildCharacterState::Mission:
		//����Ʈ â
		//����Ʈ�� ������ Die �� 
		break;
	case EAIChildCharacterState::Die:
		break;
	}
}

void AAIChildCharacter::TickComplete(const float& DeltaTime)
{
	//���� ��� �ø���
	//440.150001
	 //Ÿ�̸� ���
	//�÷��̾� ���� ��ġ���� �̵��Ѵ�.
	float Speed = 5.0f;  // �̵� �ӵ�

	FVector NewLocation = FMath::VInterpTo(GetActorLocation(), EndLocation, DeltaTime, Speed);
	SetActorLocation(NewLocation);

	FTimerHandle stopTimerHandle1;
	GetWorld()->GetTimerManager().SetTimer(stopTimerHandle1, this, &AAIChildCharacter::SetMissionState, 1.5f, false);
}
void AAIChildCharacter::TickSelected(const float& DeltaTime)
{
	//��¦ ����ٴ� �ִϸ��̼� ���� ������ ���� ��
	//TickComplete ���·� ��ȯ

	
}
void AAIChildCharacter::TickDie(const float& DeltaTime)
{
}
void AAIChildCharacter::TickIdle(const float& DeltaTime)
{
}
void AAIChildCharacter::TickMission(const float& DeltaTime)
{

}

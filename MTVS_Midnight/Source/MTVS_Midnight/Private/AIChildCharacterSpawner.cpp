// Fill out your copyright notice in the Description page of Project Settings.


#include "AIChildCharacterSpawner.h"
#include "AIChildCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "HSW_Player.h"
// Sets default values
AAIChildCharacterSpawner::AAIChildCharacterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIChildCharacterSpawner::BeginPlay()
{
	Super::BeginPlay();
	//Select Only One
	// //spawner select One
	// //player->bCanLookBack == 0 
	// //bCanMove = true -> Select one move
	FActorSpawnParameters SpawnParams;
	characterAI1 = GetWorld()->SpawnActor<AAIChildCharacter>(aiChildCharacterFactory, (GetActorLocation() + FVector(200, 0.f, 0)), GetActorRotation()); // (GetActorLocation() + FVector(0, 50.f, 0)), GetActorRotation());
	if(NewSkeletalMesh1)
		characterAI1->NewSkeletalMesh = NewSkeletalMesh1;
	characterAI2 = GetWorld()->SpawnActor<AAIChildCharacter>(aiChildCharacterFactory, (GetActorLocation() + FVector(600.f, 0, 0)), GetActorRotation()); // (GetActorLocation() + FVector(0, 150.f, 0)), GetActorRotation());
	if (NewSkeletalMesh2)
		characterAI2->NewSkeletalMesh = NewSkeletalMesh2;
	characterAI3 = GetWorld()->SpawnActor<AAIChildCharacter>(aiChildCharacterFactory, (GetActorLocation() + FVector(-200.f, 0, 0)), GetActorRotation()); // (GetActorLocation() + FVector(0, -50.f, 0)), GetActorRotation());
	if (NewSkeletalMesh3)
		characterAI3->NewSkeletalMesh = NewSkeletalMesh3;
	characterAI4 = GetWorld()->SpawnActor<AAIChildCharacter>(aiChildCharacterFactory, (GetActorLocation() + FVector(-600.f, 0, 0)), GetActorRotation()); // (GetActorLocation() + FVector(0, -150.f, 0)), GetActorRotation());
	CheckSpeed(1);
	CheckSpeed(2);
	CheckSpeed(3);
	CheckSpeed(4);
	//플레이어 찾기
	player = Cast<AHSW_Player>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player)
		bCanLookBack = player->bCanLookBack;
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AAIChildCharacterSpawner::SetStart, 3, false);
}
void AAIChildCharacterSpawner::TouchEnemy(int32 num)
{
	if (touchEnemyNum == 0)
	{
		touchEnemyNum = num;
	}
	else if (touchEnemyNum == num)
	{
		touchEnemyNumCount++;
		if (touchEnemyNumCount >= 10)
		{
			switch (touchEnemyNum)
			{
			case 1:
				characterAI1->TouchEnemy();
				break;
			case 2:
				characterAI2->TouchEnemy();
				break;
			case 3:
				characterAI3->TouchEnemy();
				break;
			case 4:
				characterAI4->TouchEnemy();
				break;
			default:
				break;
			}
		}
	}
	else
	{
		touchEnemyNumCount = 0;
		touchEnemyNum = num;
	}
}
void AAIChildCharacterSpawner::SetStart()
{
	bGameStart = true;
}
void AAIChildCharacterSpawner::CheckSpeed(int32 numAI)
{
	switch (numAI)
	{
	case 1:
		if (characterAI2->moveSpeed == characterAI1->moveSpeed 
		|| characterAI3->moveSpeed == characterAI1->moveSpeed 
		|| characterAI4->moveSpeed == characterAI1->moveSpeed)
		{
			float randFloat = FMath::RandRange(0.1, 1.0);
			characterAI1->randomScaleSpeed = randFloat;

		}
		break;
	case 2:
		if (characterAI1->moveSpeed == characterAI2->moveSpeed
			|| characterAI3->moveSpeed == characterAI2->moveSpeed
			|| characterAI4->moveSpeed == characterAI2->moveSpeed)
		{
			float randFloat = FMath::RandRange(0.1, 1.0);
			characterAI1->randomScaleSpeed = randFloat;

		}
		break;
	case 3:
		if (characterAI1->moveSpeed == characterAI3->moveSpeed
			|| characterAI2->moveSpeed == characterAI3->moveSpeed
			|| characterAI4->moveSpeed == characterAI3->moveSpeed)
		{
			float randFloat = FMath::RandRange(0.1, 1.0);
			characterAI1->randomScaleSpeed = randFloat;

		}
		break;
	case 4:
		if (characterAI1->moveSpeed == characterAI4->moveSpeed
			|| characterAI2->moveSpeed == characterAI4->moveSpeed
			|| characterAI3->moveSpeed == characterAI4->moveSpeed)
		{
			float randFloat = FMath::RandRange(0.1, 1.0);
			characterAI1->randomScaleSpeed = randFloat;

		}
		break;
	default:
		break;
	}
}
// Called every frame
void AAIChildCharacterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (characterAI1 && characterAI2 && characterAI3 && characterAI4)
	{
		if (player && bGameStart)
		{
			if (bCanLookBack != player->bCanLookBack)
			{
				bCanLookBack = player->bCanLookBack;
				//Select Only One
				// //spawner select One
				// //player->bCanLookBack == 0 
				// //bCanMove = true -> Select one move
				if (!bCanLookBack) //player don't look back
				{
					//spawner select One
					int32 randNum = FMath::RandRange(1, 4);
					int32 randNumSpeed = FMath::RandRange(1, 10);
					float randFloat = FMath::RandRange(0.1, 1.0);
					switch (randNum)
					{
					case 1:
						characterAI1->randomScaleSpeed = randFloat;
						CheckSpeed(1);
						characterAI1->bCanMove = true;
						characterAI2->bCanMove = false;
						characterAI3->bCanMove = false;
						characterAI4->bCanMove = false;
						break;
					case 2:
						characterAI2->randomScaleSpeed = randFloat;
						CheckSpeed(2);
						characterAI1->bCanMove = false;
						characterAI2->bCanMove = true;
						characterAI3->bCanMove = false;
						characterAI4->bCanMove = false;
						break;
					case 3:
						characterAI3->randomScaleSpeed = randFloat;
						CheckSpeed(3);
						characterAI1->bCanMove = false;
						characterAI2->bCanMove = false;
						characterAI3->bCanMove = true;
						characterAI4->bCanMove = false;
						break;
					case 4:
						characterAI4->randomScaleSpeed = randFloat;
						CheckSpeed(4);
						characterAI1->bCanMove = false;
						characterAI2->bCanMove = false;
						characterAI3->bCanMove = false;
						characterAI4->bCanMove = true;
						break;
					default:
						break;
					}
				}
			}
		}
	}
}	   


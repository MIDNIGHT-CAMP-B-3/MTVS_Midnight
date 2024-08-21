// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIChildCharacter.generated.h"

UENUM(BlueprintType)
enum class EAIChildCharacterState :uint8 {
	IDLE,
	STOP ,
	MOVE ,
	Complete,
	Selected,
	Die,
	Mission,
};

UCLASS()
class MTVS_MIDNIGHT_API AAIChildCharacter : public ACharacter
{
	GENERATED_BODY()
	FTimerHandle stopTimerHandle;

	bool checkNum;

	FVector StartLocation;
	FVector EndLocation;
	bool bCanLookBack;
	bool bGameStart;
	class AHSW_Player* player;
public:
	int32 numLine;
	bool walkStyle1;
	bool walkStyle2;
	float randomScaleSpeed = 1.0f;
	float moveSpeed = 10.0f;
	// Sets default values for this character's properties
	AAIChildCharacter();
		UPROPERTY()
		EAIChildCharacterState State = EAIChildCharacterState::IDLE;
		UPROPERTY(EditAnywhere,category = "ChildCharacter")
		float goalDistance;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool bCanMove;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void SetCompleteState();
	void TouchEnemy();
	   // Skeletal Mesh 변수 선언 (블루프린트에서 설정 가능)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    class USkeletalMesh* NewSkeletalMesh;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
	class USkeletalMesh* NewSkeletalMesh2;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
	class  USkeletalMesh* NewSkeletalMesh3;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    TSubclassOf<class UAIChildCharacterAnimInstance> AnimInstanceClass1;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    TSubclassOf<class UAIChildCharacterAnimInstance> AnimInstanceClass2;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    TSubclassOf<class UAIChildCharacterAnimInstance> AnimInstanceClass3;
	    UFUNCTION(BlueprintCallable, Category = "SkeletalMesh")
    void ApplySkeletalMesh();

		  UPROPERTY(EditAnywhere, Category = "Custom")
    TSubclassOf<AActor> BalloonActorClass1;
	  UPROPERTY(EditAnywhere, Category = "Custom")
    TSubclassOf<AActor> BalloonActorClass2;
	  UPROPERTY(EditAnywhere, Category = "Custom")
    TSubclassOf<AActor> BalloonActorClass3;
	  UPROPERTY(EditAnywhere, Category = "Custom")
    TSubclassOf<AActor> BalloonActorClass4;
	class  AActor* BalloonActorInstance1;
	class AActor* BalloonActorInstance2;
	class AActor* BalloonActorInstance3;
	class AActor* BalloonActorInstance4;
private:
	TArray<class FString> words;
	FVector startLocation;
	class UAIChildCharacterAnimInstance* anim;
	void TickIdle(const float& DeltaTime);
	void TickMission(const float& DeltaTime);
	void TickStop(const float& DeltaTime);
	void TickMove(const float& DeltaTime);
	void SetMoveState();
	void SetStopState();
	void SetMissionState();
	void SetState(EAIChildCharacterState NextState);
	void TickComplete(const float& DeltaTime);
	void TickSelected(const float& DeltaTime);
	void TickDie(const float& DeltaTime);
};

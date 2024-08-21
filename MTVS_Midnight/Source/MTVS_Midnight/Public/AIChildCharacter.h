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
};

UCLASS()
class MTVS_MIDNIGHT_API AAIChildCharacter : public ACharacter
{
	GENERATED_BODY()
	FVector StartLocation;
	FVector EndLocation;
	bool bCanLookBack;
	bool bGameStart;
	class AHSW_Player* player;
public:
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
private:

	FVector startLocation;
	class UAIChildCharacterAnimInstance* anim;
	void TickIdle(const float& DeltaTime);
	void TickStop(const float& DeltaTime);
	void TickMove(const float& DeltaTime);
	void SetMoveState();
	void SetStopState();
	void SetState(EAIChildCharacterState NextState);
	void TickComplete(const float& DeltaTime);
	void TickSelected(const float& DeltaTime);
	void TickDie(const float& DeltaTime);
};

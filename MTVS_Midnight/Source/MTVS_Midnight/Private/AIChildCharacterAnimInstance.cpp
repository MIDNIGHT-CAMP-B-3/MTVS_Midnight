// Fill out your copyright notice in the Description page of Project Settings.


#include "AIChildCharacterAnimInstance.h"
#include <AIChildCharacter.h>
void UAIChildCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (!OnMontageEnded.IsAlreadyBound(this, &UAIChildCharacterAnimInstance::HandleOnMontageEnded))
		OnMontageEnded.AddDynamic(this, &UAIChildCharacterAnimInstance::HandleOnMontageEnded);
}
void UAIChildCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	owner = Cast< AAIChildCharacter>(TryGetPawnOwner());
	if (!owner)
	{
		return;
	}
	FVector velocity = owner->GetVelocity();
	FVector forwardVector = owner->GetActorForwardVector();
	//앞뒤 속도 //max speed 600
	Speed = FVector::DotProduct(forwardVector, velocity);

	PlayRateWalk=owner->randomScaleSpeed * 1.5;

	walkStyle1 = owner->walkStyle1;
	walkStyle2 = owner->walkStyle2;
}
void UAIChildCharacterAnimInstance::HandleOnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	// Montage가 끝났을 때의 처리 로직
	if (bInterrupted)
	{

	}
	else
	{
		// Animation Montage가 정상적으로 끝났습니다.
		if (surprisedMontage == Montage)
		{
			owner->SetCompleteState();
		}
	}
}
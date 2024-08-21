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
	//�յ� �ӵ� //max speed 600
	Speed = FVector::DotProduct(forwardVector, velocity);

	PlayRateWalk=owner->randomScaleSpeed * 1.5;

	walkStyle1 = owner->walkStyle1;
	walkStyle2 = owner->walkStyle2;
}
void UAIChildCharacterAnimInstance::HandleOnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	// Montage�� ������ ���� ó�� ����
	if (bInterrupted)
	{

	}
	else
	{
		// Animation Montage�� ���������� �������ϴ�.
		if (surprisedMontage == Montage)
		{
			owner->SetCompleteState();
		}
	}
}
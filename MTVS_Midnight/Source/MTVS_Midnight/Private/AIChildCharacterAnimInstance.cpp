// Fill out your copyright notice in the Description page of Project Settings.


#include "AIChildCharacterAnimInstance.h"
#include <AIChildCharacter.h>

void UAIChildCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	AAIChildCharacter* owner = Cast< AAIChildCharacter>(TryGetPawnOwner());
	if (!owner)
	{
		return;
	}
	FVector velocity = owner->GetVelocity();
	FVector forwardVector = owner->GetActorForwardVector();
	//앞뒤 속도 //max speed 600
	Speed = FVector::DotProduct(forwardVector, velocity);
	UE_LOG(LogTemp, Error, TEXT("%f"), Speed);
	PlayRateWalk=owner->randomScaleSpeed * 1.5;

	walkStyle1 = owner->walkStyle1;
	walkStyle2 = owner->walkStyle2;
}

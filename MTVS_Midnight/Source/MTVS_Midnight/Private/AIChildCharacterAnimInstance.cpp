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
	//앞뒤 속도
	Speed = FVector::DotProduct(forwardVector, velocity);
	UE_LOG(LogTemp,Warning,TEXT("%f"),Speed);
}

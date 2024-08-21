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
	//�յ� �ӵ�
	Speed = FVector::DotProduct(forwardVector, velocity);
	UE_LOG(LogTemp,Warning,TEXT("%f"),Speed);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIChildCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API UAIChildCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds);
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float Speed;
};

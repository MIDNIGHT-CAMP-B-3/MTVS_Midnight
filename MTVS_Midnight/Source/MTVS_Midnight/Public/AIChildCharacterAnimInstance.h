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

	virtual void NativeInitializeAnimation();
	UFUNCTION()
	virtual void HandleOnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	virtual void NativeUpdateAnimation(float DeltaSeconds);
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float Speed;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float PlayRateWalk;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	bool walkStyle1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	bool walkStyle2;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	bool bSelected;
	class AAIChildCharacter* owner;
		UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	class UAnimMontage* surprisedMontage;
};

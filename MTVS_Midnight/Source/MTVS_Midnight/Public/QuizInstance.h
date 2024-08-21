// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "QuizInstance.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API UQuizInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY()
	class UQuizWidget* QuizWidgetInstance;

	int32 score;
	float playtime = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuizGameMode.h"
#include "StartWidjet.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API UStartWidjet : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* StartButton;

    UFUNCTION()
    void OnStartButtonClicked();

    UPROPERTY()
    class AQuizGameMode* QuizGM;
};

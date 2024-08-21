// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "QuizGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API AQuizGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	AQuizGameMode();

    // ���� Ŭ������ ���� ������ �����ϴ� ����
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UQuizWidget> QuizWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UEndWidget> EndWidgetClass;

private:
    class UQuizWidget* QuizWidget;
    class UEndWidget* EndWidget;

public:
	virtual void BeginPlay();
    virtual void Tick();
    UFUNCTION()
    void ChangeWidget();
};

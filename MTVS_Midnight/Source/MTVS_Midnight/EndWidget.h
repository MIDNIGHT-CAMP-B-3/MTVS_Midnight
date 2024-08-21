// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuizWidget.h"
#include "EndWidget.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API UEndWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeBeginPlay();
	virtual void NativeConstruct() override;


    // ���� ���� ������ �����ϴ� �Լ�
    UFUNCTION(BlueprintCallable)
    void SetQuizWidgetReference(UQuizWidget* QuizWidget);

    UPROPERTY(BlueprintReadWrite)
    class UQuizWidget* quiz;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PlayTimeText;

    UPROPERTY()
    class UQuizInstance* quizIns;

};

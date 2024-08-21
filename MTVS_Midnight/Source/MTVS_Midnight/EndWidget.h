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
	virtual void NativeConstruct() override;


    // 퀴즈 위젯 참조를 설정하는 함수
    UFUNCTION(BlueprintCallable)
    void SetQuizWidgetReference(UQuizWidget* QuizWidget);

    UPROPERTY(BlueprintReadWrite)
    class UQuizWidget* quiz;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PlayTimeText;

   // void SetScore(int32 score);

    //int32 EndScore;
    /*UPROPERTY(meta = (BindWidget))
    class UTextBlock* CorrectAnswerText;
    
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* WrongAnswerText;*/
};

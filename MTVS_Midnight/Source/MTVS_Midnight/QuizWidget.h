// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuizGameMode.h"
#include "QuizWidget.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API UQuizWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    // 각 버튼에 대한 클릭 이벤트 처리 함수
    UFUNCTION()
    void OnAnswerButton1Clicked();

    UFUNCTION()
    void OnAnswerButton2Clicked();

public:
	virtual void BeginPlay() ;

    virtual void NativeConstruct() override;

    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    // 플레이 타임
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    float PlayTime;

    // 현재 점수
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    int32 Score;

    // 정답 문자열
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    FString CorrectAnswer = "Apple";
    
    // 플레이 타임 텍스트
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PlayTimeText;

    // 퀴즈 질문 텍스트
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* QuestionText;

    /*UPROPERTY(meta = (BindWidget))
    class UBorder*/

    // 점수 텍스트
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    // 정답/오답 피드백 텍스트
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* FeedbackText;

     // 답변 버튼들
    UPROPERTY(meta = (BindWidget))
    class UButton* AnswerButton1;

    UPROPERTY(meta = (BindWidget))
    class UButton* AnswerButton2;

    // 선택된 답변을 처리하는 함수
    void OnAnswerSelected(const FString& SelectedAnswer);

    // UI 업데이트 함수
    void UpdatePlayTimeDisplay(float DeltaSeconds);
    void UpdateScoreDisplay();
    void ShowFeedback(bool bIsCorrect);

    void HiddenFeedbackText();

    void VisibleQuestion();
    void HiddenQuestion();

    UPROPERTY(meta = (BindWidget))
    class UImage* hp1;
    UPROPERTY(meta = (BindWidget))
    class UImage* hp2;
    UPROPERTY(meta = (BindWidget))
    class UImage* hp3;

    UPROPERTY(BlueprintReadWrite)
    int32 PlayerHP = 3;

    // 플레이어 데미지 처리 함수
    UFUNCTION()
    void PlayerDamage(int32 damage);

    UPROPERTY()
    class UQuizInstance* quizIns;

    UPROPERTY()
    class AQuizGameMode* QuizGM;

};
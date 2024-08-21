// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuizWidget.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API UQuizWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    // �� ��ư�� ���� Ŭ�� �̺�Ʈ ó�� �Լ�
    UFUNCTION()
    void OnAnswerButton1Clicked();

    UFUNCTION()
    void OnAnswerButton2Clicked();

protected:
    virtual void NativeConstruct() override;

    // ���� ����
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    int32 Score;

    // ���� ���ڿ�
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    FString CorrectAnswer = "Apple";

    // ���� ���� �ؽ�Ʈ
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* QuestionText;

    // ���� �ؽ�Ʈ
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    // ����/���� �ǵ�� �ؽ�Ʈ
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* FeedbackText;

     // �亯 ��ư��
    UPROPERTY(meta = (BindWidget))
    class UButton* AnswerButton1;

    UPROPERTY(meta = (BindWidget))
    class UButton* AnswerButton2;

    // ���õ� �亯�� ó���ϴ� �Լ�
    void OnAnswerSelected(const FString& SelectedAnswer);

    // UI ������Ʈ �Լ�
    void UpdateScoreDisplay();
    void ShowFeedback(bool bIsCorrect);
};
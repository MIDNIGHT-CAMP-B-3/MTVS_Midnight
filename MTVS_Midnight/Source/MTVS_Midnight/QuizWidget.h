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
    // �� ��ư�� ���� Ŭ�� �̺�Ʈ ó�� �Լ�
    UFUNCTION()
    void OnAnswerButton1Clicked();

    UFUNCTION()
    void OnAnswerButton2Clicked();

public:
	virtual void BeginPlay() ;

    virtual void NativeConstruct() override;

    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    // �÷��� Ÿ��
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    float PlayTime;

    // ���� ����
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    int32 Score;

    // ���� ���ڿ�
    UPROPERTY(BlueprintReadOnly, Category = "Quiz")
    FString CorrectAnswer = "Apple";
    
    // �÷��� Ÿ�� �ؽ�Ʈ
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PlayTimeText;

    // ���� ���� �ؽ�Ʈ
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* QuestionText;

    /*UPROPERTY(meta = (BindWidget))
    class UBorder*/

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

    // �÷��̾� ������ ó�� �Լ�
    UFUNCTION()
    void PlayerDamage(int32 damage);

    UPROPERTY()
    class UQuizInstance* quizIns;

    UPROPERTY()
    class AQuizGameMode* QuizGM;

};
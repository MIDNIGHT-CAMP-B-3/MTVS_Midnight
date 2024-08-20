// Fill out your copyright notice in the Description page of Project Settings.


#include "QuizWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UQuizWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // �ʱ� ���� ����
    Score = 0;
    UpdateScoreDisplay();

    // �� ��ư�� Ŭ�� �̺�Ʈ ����
    if (AnswerButton1)
    {
        AnswerButton1->OnClicked.AddDynamic(this, &UQuizWidget::OnAnswerButton1Clicked);
    }

    if (AnswerButton2)
    {
        AnswerButton2->OnClicked.AddDynamic(this, &UQuizWidget::OnAnswerButton2Clicked);
    }

    // �ʱ� �ǵ�� �ؽ�Ʈ �����
    if (FeedbackText)
    {
        FeedbackText->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UQuizWidget::OnAnswerButton1Clicked()
{
    // ��ư 1�� Ŭ���Ǿ��� �� ó���� ����
    OnAnswerSelected(TEXT("Apple"));  // ���� �亯
}

void UQuizWidget::OnAnswerButton2Clicked()
{
    // ��ư 2�� Ŭ���Ǿ��� �� ó���� ����
    OnAnswerSelected(TEXT("Banana"));  // ���� �亯
}

void UQuizWidget::OnAnswerSelected(const FString& SelectedAnswer)
{
    if (SelectedAnswer.Equals(CorrectAnswer, ESearchCase::IgnoreCase))
    {
        Score++;
        ShowFeedback(true);
    }
    else
    {
        ShowFeedback(false);
    }

    UpdateScoreDisplay();
}

void UQuizWidget::UpdateScoreDisplay()
{
    if (ScoreText)
    {
        ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), Score)));
    }
}

void UQuizWidget::ShowFeedback(bool bIsCorrect)
{
    if (FeedbackText)
    {
        if (bIsCorrect)
        {
            FeedbackText->SetText(FText::FromString("Correct!"));
        }
        else
        {
            FeedbackText->SetText(FText::FromString("Wrong!"));
        }

        FeedbackText->SetVisibility(ESlateVisibility::Visible);

        // ���� �ð� �� �ǵ�� ����� (�񵿱������� ó�� ����)
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
            {
                FeedbackText->SetVisibility(ESlateVisibility::Hidden);
            }), 2.0f, false);
    }
}
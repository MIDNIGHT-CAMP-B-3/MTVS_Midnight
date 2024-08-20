// Fill out your copyright notice in the Description page of Project Settings.


#include "QuizWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UQuizWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 초기 점수 설정
    Score = 0;
    UpdateScoreDisplay();

    // 각 버튼에 클릭 이벤트 연결
    if (AnswerButton1)
    {
        AnswerButton1->OnClicked.AddDynamic(this, &UQuizWidget::OnAnswerButton1Clicked);
    }

    if (AnswerButton2)
    {
        AnswerButton2->OnClicked.AddDynamic(this, &UQuizWidget::OnAnswerButton2Clicked);
    }

    // 초기 피드백 텍스트 숨기기
    if (FeedbackText)
    {
        FeedbackText->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UQuizWidget::OnAnswerButton1Clicked()
{
    // 버튼 1이 클릭되었을 때 처리할 내용
    OnAnswerSelected(TEXT("Apple"));  // 예시 답변
}

void UQuizWidget::OnAnswerButton2Clicked()
{
    // 버튼 2가 클릭되었을 때 처리할 내용
    OnAnswerSelected(TEXT("Banana"));  // 예시 답변
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

        // 일정 시간 후 피드백 숨기기 (비동기적으로 처리 가능)
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
            {
                FeedbackText->SetVisibility(ESlateVisibility::Hidden);
            }), 2.0f, false);
    }
}
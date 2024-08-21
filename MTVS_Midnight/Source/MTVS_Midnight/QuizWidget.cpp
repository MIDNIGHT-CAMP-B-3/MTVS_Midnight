// Fill out your copyright notice in the Description page of Project Settings.


#include "QuizWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "QuizInstance.h"
#include "QuizGameMode.h"
#include "../QuizWidget.h"
#include "../EndWidget.h"

void UQuizWidget::BeginPlay()
{
    
}

void UQuizWidget::NativeConstruct()
{
    Super::NativeConstruct();

    HiddenQuestion();

    hp1->SetVisibility(ESlateVisibility::Visible);
    hp2->SetVisibility(ESlateVisibility::Visible);
    hp3->SetVisibility(ESlateVisibility::Visible);


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

void UQuizWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    // 매 프레임마다 플레이 타임을 갱신
    UpdatePlayTimeDisplay(InDeltaTime);
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
        PlayerDamage(1);
    }

    UpdateScoreDisplay();
}

void UQuizWidget::UpdatePlayTimeDisplay(float DeltaSeconds)
{
    PlayTime += DeltaSeconds;
    UE_LOG(LogTemp, Warning, TEXT("%f"), PlayTime);

    if (PlayTimeText)
    {
        PlayTimeText->SetText(FText::FromString(FString::Printf(TEXT("Play Time : %d"), static_cast<int32>(PlayTime))));
    }
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
    if(!FeedbackText) return;
    else if (FeedbackText)
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
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UQuizWidget::HiddenFeedbackText, 2.f, false);
    }
}

void UQuizWidget::HiddenFeedbackText()
{
    FeedbackText->SetVisibility(ESlateVisibility::Hidden);
}

void UQuizWidget::VisibleQuestion()
{
    QuestionText->SetVisibility(ESlateVisibility::Visible);
    AnswerButton1->SetVisibility(ESlateVisibility::Visible);
    AnswerButton2->SetVisibility(ESlateVisibility::Visible);
}

void UQuizWidget::HiddenQuestion()
{
    QuestionText->SetVisibility(ESlateVisibility::Hidden);
    AnswerButton1->SetVisibility(ESlateVisibility::Hidden);
    AnswerButton2->SetVisibility(ESlateVisibility::Hidden);
}

void UQuizWidget::PlayerDamage(int32 damage)
{
    PlayerHP -= damage;
    
    if (PlayerHP == 2)
    {
        if (hp3) hp3->SetVisibility(ESlateVisibility::Hidden);
    }
    else if (PlayerHP == 1)
    {
        if (hp2) hp2->SetVisibility(ESlateVisibility::Hidden);
    }
    else if (PlayerHP <= 0)
    {
        if (hp1) hp1->SetVisibility(ESlateVisibility::Hidden);



       // if(!quizIns) return;
        quizIns = Cast<UQuizInstance>(GetGameInstance());
        if (quizIns)
        {
            quizIns->playtime += PlayTime;
            quizIns->score += Score;
        }

        QuizGM = Cast<AQuizGameMode>(GetWorld()->GetAuthGameMode());
        QuizGM->ChangeWidget();


        //QuizGM = Cast<AQuizGameMode>(GetWorld()->GetAuthGameMode());

        //SwitchLevel();
    }
}


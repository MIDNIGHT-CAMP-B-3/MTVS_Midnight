// Fill out your copyright notice in the Description page of Project Settings.


#include "EndWidget.h"
#include "Components/TextBlock.h"
#include "QuizWidget.h"

void UEndWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//EndScore = quiz->Score;
	//ScoreText->SetText(FText::AsNumber(EndScore));
	if(!quiz) return;

	if (ScoreText && quiz)
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), quiz->Score)));
		//UE_LOG(LogTemp, Warning, TEXT("End Score Text"));
	}

	if (PlayTimeText && quiz)
	{
		PlayTimeText->SetText(FText::FromString(FString::Printf(TEXT("Play Time: %d"), quiz->PlayTime)));
		//UE_LOG(LogTemp, Warning, TEXT("Play Time Text"));
	}

    /*if (CorrectAnswerText)
	{
		CorrectAnswerText->SetText(FText::FromString(FString::Printf(TEXT(" %s"), quiz->CorrectAnswer)));
    }*/

    /*if (WrongAnswerText)
    {
        WrongAnswerText->SetText(FText::FromString(FString::Printf(TEXT(" %s"), quiz->)));
    }*/

}

void UEndWidget::SetQuizWidgetReference(UQuizWidget* QuizWidget)
{
	if (QuizWidget == nullptr) return;
	if (quiz && QuizWidget)
	{
	quiz = QuizWidget;
	//UE_LOG(LogTemp, Warning, TEXT("QuizWidget Instance Set: %p"), quiz);
	}
}

//void UEndWidget::SetScore(int32 score)
//{
//	ScoreText->SetText(FText::AsNumber(score));
//}

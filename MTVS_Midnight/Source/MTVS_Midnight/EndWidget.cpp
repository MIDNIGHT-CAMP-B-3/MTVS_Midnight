// Fill out your copyright notice in the Description page of Project Settings.


#include "EndWidget.h"
#include "Components/TextBlock.h"
#include "QuizWidget.h"
#include "QuizInstance.h"

void UEndWidget::NativeBeginPlay()
{
	
	quizIns = Cast<UQuizInstance>(GetGameInstance());

}

void UEndWidget::NativeConstruct()
{
	Super::NativeConstruct();
	quizIns = Cast<UQuizInstance>(GetGameInstance());
	//if(!quiz) return;
	//if(!quizIns->QuizWidgetInstance) return;
	//if (quiz /*&& quizIns->QuizWidgetInstance*/)
	//{
	//}

		if (ScoreText)
		{
			ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), quizIns->score)));
			UE_LOG(LogTemp, Warning, TEXT("End Score Text"));
		}
		if (PlayTimeText)
		{
			PlayTimeText->SetText(FText::FromString(FString::Printf(TEXT("Play Time: %.f"), quizIns->playtime)));
			UE_LOG(LogTemp, Warning, TEXT("Play Time Text"));
		}
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

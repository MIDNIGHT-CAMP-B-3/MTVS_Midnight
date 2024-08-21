// Fill out your copyright notice in the Description page of Project Settings.


#include "QuizGameMode.h"
#include "../QuizWidget.h"
#include "../EndWidget.h"
#include "UObject/ConstructorHelpers.h"

AQuizGameMode::AQuizGameMode()
{
	// 위젯 클래스를 기본값으로 설정 (Blueprint에서 설정해도 됨)
	static ConstructorHelpers::FClassFinder<UQuizWidget> WidgetBPClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/LHM/Widget/WBP_Quiz.WBP_Quiz'"));
	if (WidgetBPClass.Class != nullptr)
	{
		QuizWidgetClass = WidgetBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UEndWidget> EndWidgetBPClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/LHM/Widget/WBP_End.WBP_End'"));
	if (EndWidgetBPClass.Class != nullptr)
	{
		EndWidgetClass = EndWidgetBPClass.Class;
	}

}

void AQuizGameMode::BeginPlay()
{
	Super::BeginPlay();

	// 서버에서만 UI 생성 로직이 실행되지 않도록 주의
	if (IsValid(QuizWidgetClass))
	{
		QuizWidget = CreateWidget<UQuizWidget>(GetWorld(), QuizWidgetClass);
		if (QuizWidget)
		{
			QuizWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("Quiz Widget created and added to viewport"));
		}
	}

	if (IsValid(EndWidgetClass))
	{	
		EndWidget = CreateWidget<UEndWidget>(GetWorld(), EndWidgetClass);
	}
}

void AQuizGameMode::Tick()
{
	//Super::Tick();

}

void AQuizGameMode::ChangeWidget()
{		
	UE_LOG(LogTemp, Warning, TEXT("Player HP 0!!!!!!!!!!!!!!"));
	if(!this) return;
	else if (this)
	{
		if(EndWidget) EndWidget->AddToViewport();
		if (QuizWidget) QuizWidget->SetVisibility(ESlateVisibility::Hidden);
		UE_LOG(LogTemp, Warning, TEXT("End Widget created and added to viewport"));
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "QuizGameMode.h"
#include "../QuizWidget.h"
#include "../EndWidget.h"
#include "UObject/ConstructorHelpers.h"

AQuizGameMode::AQuizGameMode()
{
	// ���� Ŭ������ �⺻������ ���� (Blueprint���� �����ص� ��)
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

	// ���������� UI ���� ������ ������� �ʵ��� ����
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


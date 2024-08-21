// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameMode.h"
#include "../StartWidjet.h"

AStartGameMode::AStartGameMode()
{
	// ���� Ŭ������ �⺻������ ���� (Blueprint���� �����ص� ��)
	static ConstructorHelpers::FClassFinder<UStartWidjet> WidgetBPClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/LHM/Widget/WBP_Start.WBP_Start'"));
	if (WidgetBPClass.Class != nullptr)
	{
		WidgetClass = WidgetBPClass.Class;
	}
}

void AStartGameMode::BeginPlay()
{
	Super::BeginPlay();

	// ���������� UI ���� ������ ������� �ʵ��� ����
	if (IsValid(WidgetClass))
	{
		CurrentWidget = CreateWidget<UStartWidjet>(GetWorld(), WidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("Widget created and added to viewport"));
		}
	}
}

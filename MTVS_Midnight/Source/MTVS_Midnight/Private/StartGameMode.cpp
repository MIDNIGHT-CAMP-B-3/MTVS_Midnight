// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameMode.h"
#include "../StartWidjet.h"

AStartGameMode::AStartGameMode()
{
	// 위젯 클래스를 기본값으로 설정 (Blueprint에서 설정해도 됨)
	static ConstructorHelpers::FClassFinder<UStartWidjet> WidgetBPClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/LHM/Widget/WBP_Start.WBP_Start'"));
	if (WidgetBPClass.Class != nullptr)
	{
		WidgetClass = WidgetBPClass.Class;
	}
}

void AStartGameMode::BeginPlay()
{
	Super::BeginPlay();

	// 서버에서만 UI 생성 로직이 실행되지 않도록 주의
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

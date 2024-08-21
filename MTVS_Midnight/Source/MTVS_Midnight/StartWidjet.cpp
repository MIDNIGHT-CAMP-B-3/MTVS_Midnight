// Fill out your copyright notice in the Description page of Project Settings.


#include "StartWidjet.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "QuizGameMode.h"

void UStartWidjet::NativeConstruct()
{
	Super::NativeConstruct();


    if (StartButton)
    {
        StartButton->OnClicked.AddDynamic(this, &UStartWidjet::OnStartButtonClicked);
    }
}

void UStartWidjet::OnStartButtonClicked()
{   
	//QuizGM = Cast<AQuizGameMode>(GetWorld()->GetAuthGameMode());

    FString LevelName = "Min_LSJEnvironment";

    // UGameplayStatics를 사용하여 레벨 전환
    if (!LevelName.IsEmpty())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(*LevelName));
    }
}

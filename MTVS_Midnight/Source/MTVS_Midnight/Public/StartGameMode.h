// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StartGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MTVS_MIDNIGHT_API AStartGameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	AStartGameMode();

    // ���� Ŭ������ ���� ������ �����ϴ� ����
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UStartWidjet> WidgetClass;

private:
    class UStartWidjet* CurrentWidget;

public:
	virtual void BeginPlay();

};


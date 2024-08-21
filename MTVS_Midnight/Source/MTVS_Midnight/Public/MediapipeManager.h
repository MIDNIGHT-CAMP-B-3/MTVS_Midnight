// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MediapipeManager.generated.h"

UCLASS()
class MTVS_MIDNIGHT_API AMediapipeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMediapipeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// 클라이언트 소켓
    FSocket* ClientSocket;
    // 서버 주소
    TSharedPtr<FInternetAddr> ServerAddr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default|Values")
	FString serverIP = TEXT("192.168.1.87");//TEXT("127.0.0.1");
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default|Values")
	int32 serverPort = 3333;

	UFUNCTION(BlueprintCallable)
	// 서버와 연결하기
    void CreateClient();
    // 데이터 받기
    UFUNCTION(BlueprintCallable)
    void ReceiveData();

	UPROPERTY()
	class AHSW_Player* Player;

	UPROPERTY()
	class AAIChildCharacterSpawner* ChildSpawner;

};

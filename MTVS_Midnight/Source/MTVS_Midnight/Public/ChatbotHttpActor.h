// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HttpFwd.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "ChatbotHttpActor.generated.h"

UCLASS()
class MTVS_MIDNIGHT_API AChatbotHttpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChatbotHttpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 인터페이스를 위한 UI
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UQuizWidget> QuizUIFactory;

	UPROPERTY()
	class UQuizWidget* QuizUI;

	// ButtonSend를 눌렀을 때 요청할 함수
	void ReqNewBookInfo(FString url);
	// 응답받을 함수
	void OnResNewBookInfo(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

	// ButtonSendPost를 눌렀을 때 요청할 함수
	void ReqPostTest(FString url, FString json);
	// 응답받을 함수
	void OnResPostTest(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);


	// 웹이미지를 백엔드 서버로 송신
	void ReqGetWebImageToServer(FString url, TArray<uint8> resource);
	// 웹이미지를 백엔드 서버에서 수신
	void OnResGetWebImageFromServer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

};

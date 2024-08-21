// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatbotHttpActor.h"
#include "../QuizWidget.h"
#include "UJsonParseLib.h"
#include "HttpModule.h"
#include "ImageUtils.h"


// Sets default values
AChatbotHttpActor::AChatbotHttpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChatbotHttpActor::BeginPlay()
{
	Super::BeginPlay();
	
	// UI를 생성해서 기억하고싶다.
	QuizUI = Cast<UQuizWidget>(CreateWidget(GetWorld(), QuizUIFactory));
	if (QuizUI)
	{
		QuizUI->AddToViewport();
		QuizUI->SetHttpActor(this);
	}

	auto* pc = GetWorld()->GetFirstPlayerController();
	pc->SetShowMouseCursor(true);
	pc->SetInputMode(FInputModeUIOnly());
}

// Called every frame
void AChatbotHttpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AChatbotHttpActor::ReqNewBookInfo(FString url)
{
	// Http모듈을 생성
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	// 요청할 정보를 설정
	req->SetURL(url);
	req->SetVerb(TEXT("GET"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	// 응답받을 함수를 연결
	req->OnProcessRequestComplete().BindUObject(this, &AChatbotHttpActor::OnResNewBookInfo);
	// 서버에 요청

	req->ProcessRequest();
}

void AChatbotHttpActor::OnResNewBookInfo(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		// 성공
		FString result = Response->GetContentAsString();

		// 필요한 정보만 뽑아서 화면에 출력하고싶다.
		QuizUI->SetTextLog(UUJsonParseLib::JsonParse(result));
	}
	else {
		// 실패
		UE_LOG(LogTemp, Warning, TEXT("OnResNewBookInfo Failed..."));
	}
}

void AChatbotHttpActor::ReqPostTest(FString url, FString json)
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	// 요청할 정보를 설정
	req->SetURL(url);
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(json);

	// 응답받을 함수를 연결
	req->OnProcessRequestComplete().BindUObject(this, &AChatbotHttpActor::OnResPostTest);
	// 서버에 요청

	req->ProcessRequest();
}

void AChatbotHttpActor::OnResPostTest(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		// 성공
		FString result = Response->GetContentAsString();

		// 필요한 정보만 뽑아서 화면에 출력하고싶다.
		QuizUI->SetTextLog(result);
	}
	else {
		// 실패
		UE_LOG(LogTemp, Warning, TEXT("OnResPostTest Failed..."));
	}
}


void AChatbotHttpActor::ReqGetWebImageToServer(FString url, TArray<uint8> resource)
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	// 요청할 정보를 설정
	req->SetURL(url);
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/octet-stream"));
	req->SetContent(resource);

	// 응답받을 함수를 연결
	req->OnProcessRequestComplete().BindUObject(this, &AChatbotHttpActor::OnResGetWebImageFromServer);
	// 서버에 요청

	req->ProcessRequest();

}

void AChatbotHttpActor::OnResGetWebImageFromServer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		TArray<uint8> data = Response->GetContent();
		FString imagePath = FPaths::ProjectPersistentDownloadDir() + "/Cat.jpg";
		FFileHelper::SaveArrayToFile(data, *imagePath);
		UTexture2D* realTexture = FImageUtils::ImportBufferAsTexture2D(data);
		//QuizUI->SetWebImage(realTexture);
	}
	else {
		// 실패
		UE_LOG(LogTemp, Warning, TEXT("OnResGetWebImageFromServer Failed..."));
	}
}

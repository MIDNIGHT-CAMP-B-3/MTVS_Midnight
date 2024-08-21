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
	
	// UI�� �����ؼ� ����ϰ�ʹ�.
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
	// Http����� ����
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	// ��û�� ������ ����
	req->SetURL(url);
	req->SetVerb(TEXT("GET"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	// ������� �Լ��� ����
	req->OnProcessRequestComplete().BindUObject(this, &AChatbotHttpActor::OnResNewBookInfo);
	// ������ ��û

	req->ProcessRequest();
}

void AChatbotHttpActor::OnResNewBookInfo(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		// ����
		FString result = Response->GetContentAsString();

		// �ʿ��� ������ �̾Ƽ� ȭ�鿡 ����ϰ�ʹ�.
		QuizUI->SetTextLog(UUJsonParseLib::JsonParse(result));
	}
	else {
		// ����
		UE_LOG(LogTemp, Warning, TEXT("OnResNewBookInfo Failed..."));
	}
}

void AChatbotHttpActor::ReqPostTest(FString url, FString json)
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	// ��û�� ������ ����
	req->SetURL(url);
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(json);

	// ������� �Լ��� ����
	req->OnProcessRequestComplete().BindUObject(this, &AChatbotHttpActor::OnResPostTest);
	// ������ ��û

	req->ProcessRequest();
}

void AChatbotHttpActor::OnResPostTest(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		// ����
		FString result = Response->GetContentAsString();

		// �ʿ��� ������ �̾Ƽ� ȭ�鿡 ����ϰ�ʹ�.
		QuizUI->SetTextLog(result);
	}
	else {
		// ����
		UE_LOG(LogTemp, Warning, TEXT("OnResPostTest Failed..."));
	}
}


void AChatbotHttpActor::ReqGetWebImageToServer(FString url, TArray<uint8> resource)
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	// ��û�� ������ ����
	req->SetURL(url);
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/octet-stream"));
	req->SetContent(resource);

	// ������� �Լ��� ����
	req->OnProcessRequestComplete().BindUObject(this, &AChatbotHttpActor::OnResGetWebImageFromServer);
	// ������ ��û

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
		// ����
		UE_LOG(LogTemp, Warning, TEXT("OnResGetWebImageFromServer Failed..."));
	}
}

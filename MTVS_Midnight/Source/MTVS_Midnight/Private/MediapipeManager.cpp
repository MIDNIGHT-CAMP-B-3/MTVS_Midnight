// Fill out your copyright notice in the Description page of Project Settings.


#include "MediapipeManager.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "HSW_Player.h"
#include "Kismet/GameplayStatics.h"
#include "AIChildCharacterSpawner.h"

// Sets default values
AMediapipeManager::AMediapipeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMediapipeManager::BeginPlay()
{
	Super::BeginPlay();
	CreateClient();

	Player = Cast<AHSW_Player>(GetWorld()->GetFirstPlayerController()->GetPawn());

	ChildSpawner = Cast<AAIChildCharacterSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), AAIChildCharacterSpawner::StaticClass()));

	if (GEngine)
	{
		GEngine->bEnableOnScreenDebugMessages = true;
	}
}

// Called every frame
void AMediapipeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ReceiveData();

}

void AMediapipeManager::CreateClient()
{
	// 클라이언트 소켓 생성
	ClientSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("TCP Client"), false);
	ServerAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();


	// 서버 IP와 포트 설정
	FIPv4Address Ip;
	FIPv4Address::Parse(serverIP, Ip); // 서버의 IP 주소 (예: localhost)
	ServerAddr->SetIp(Ip.Value); // IP 주소 설정
	ServerAddr->SetPort(serverPort); // 서버 포트:


	// 서버에 연결
	FString connStr = ClientSocket->Connect(*ServerAddr) ? TEXT("Sever Connected") : TEXT("Sever Failed.");


	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("%s"), *connStr));
}

void AMediapipeManager::ReceiveData()
{
	if (ClientSocket)
	{
		GEngine->AddOnScreenDebugMessage(-1, -1.f, FColor::Green, TEXT("Exist Socket"));


		// 데이터 있으면 가져오기
		uint32 Size;
		GEngine->AddOnScreenDebugMessage(-1, -1.f, FColor::Green, FString::Printf(TEXT("%d"), ClientSocket->HasPendingData(Size)));
		while (ClientSocket->HasPendingData(Size))
		{
			TArray<uint8> ReceivedData;
			ReceivedData.SetNumUninitialized(FMath::Min(Size, 1024u));


			// 데이터 수신
			int32 BytesRead = 0;
			ClientSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), BytesRead);
			// 논블락, 이벤트 드리븐, 

			FString ReceivedString = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(ReceivedData.GetData())));
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("jk_____Received: %s"), *ReceivedString));

			if (ReceivedString[0] == TEXT('7')) 
			{
				//GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, TEXT("LookBackTrue"));
				Player->bCanLookBack = true;
			}
			else
			{
				//GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, TEXT("LookBackFalse"));
				Player->bCanLookBack = false;
			}

			ChildSpawner->TouchEnemy(ReceivedString[2]-TEXT('0'));
			// @@ 이 데이터를 사용하기

		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, -1.f, FColor::Green, TEXT("No Socket"));
	}
}


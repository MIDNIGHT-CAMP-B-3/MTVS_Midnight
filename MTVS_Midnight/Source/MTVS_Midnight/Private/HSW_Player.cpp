// Fill out your copyright notice in the Description page of Project Settings.


#include "HSW_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
//#include "WebSocketModule.h"
//#include "IWebSocket.h"
//#include "Networking/Public/Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHSW_Player::AHSW_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerStaticMesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMesh"));
	PlayerStaticMesh->SetRelativeLocationAndRotation(FVector(0, 0, -90.f), FRotator(0, -90.f, 0));
	PlayerStaticMesh->SetupAttachment(RootComponent);

	// 스프링암을 생성해서 루트에 붙이고 싶다.
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	SpringArmComp->SetRelativeLocation(FVector(696.f, 0.f, 540.f));
	SpringArmComp->SetRelativeRotation(FRotator(-5.f, 180.f, 0.f));

	SpringArmComp->TargetArmLength = 0;

	// 카메라 생성해서 스프링암에 붙이고싶다.
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AHSW_Player::BeginPlay()
{
	Super::BeginPlay();

	MugungHwuaAudioComponent = NewObject<UAudioComponent>(this);
	CheckAudioComponent = NewObject<UAudioComponent>(this);


//	MugungHwuaAudioComponent->SetSound(MugunghwuaSFV);
//	MugungHwuaAudioComponent->RegisterComponent();

	CheckAudioComponent->SetSound(MugunghwuaSFV);
	CheckAudioComponent->RegisterComponent();
	CheckAudioComponent->SetPitchMultiplier(1.1f);
	CheckAudioComponent->SetVolumeMultiplier(0);

/*	StartUDPServer();*/
/*	CreateClient();*/
}

// Called every frame
void AHSW_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//StartUDPServer();



	if ( (bCanLookBack == true) )//&& (bPlayingQuiz == false) && (!(MugungHwuaAudioComponent->IsPlaying())) 
	{
		if ((!(CheckAudioComponent->IsPlaying())) || (CurrentTime > MakeSoundTime))
		{
			PlayerStaticMesh->SetRelativeRotation(FMath::Lerp(PlayerStaticMesh->GetRelativeRotation(), LookBackRotation, 0.1f));
			CurrentTime = 0;
			bCanPlayingSound = true;
			GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("SoundOver!!"));
		}
		//GetMesh()->SetRelativeRotation(FMath::Lerp(GetMesh()->GetRelativeRotation(), LookBackRotation, 0.1f));
		//SetActorRotation(FMath::Lerp(GetActorRotation(), LookBackRotation, 0.1f));
		else
		{
			PlayerStaticMesh->SetRelativeRotation(FMath::Lerp(PlayerStaticMesh->GetRelativeRotation(), DefaultRotation, 0.1f));
		}
	}
	else if (bCanLookBack == false)
	{
		CurrentTime += DeltaTime;
		if ((!(CheckAudioComponent->IsPlaying())) && (CurrentTime > MakeSoundTime) && (bCanPlayingSound ==true))
		{
			bCanPlayingSound = false;
			GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("PlaySound"));

			CheckAudioComponent->Play();
//			MugungHwuaAudioComponent->Play();
		}
		GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Magenta, FString::Printf(TEXT("%f"),CurrentTime));
		//if ((!(MugungHwuaAudioComponent->IsPlaying()))&&(bCanPlayingSound == true))

		PlayerStaticMesh->SetRelativeRotation(FMath::Lerp(PlayerStaticMesh->GetRelativeRotation(), DefaultRotation, 0.1f));
		//GetMesh()->SetRelativeRotation(FMath::Lerp(GetMesh()->GetRelativeRotation(), DefaultRotation, 0.1f));
		//SetActorRotation(FMath::Lerp(GetActorRotation(), DefaultRotation, 0.1f));
	}
	
	


/*	ReceiveData();*/
}

// Called to bind functionality to input
void AHSW_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

 	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Pressed, this, &AHSW_Player::onMyActionLookBack);
 	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Released, this, &AHSW_Player::onMyActionLookBack);

//	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Pressed, this, & AHSW_Player::TurnBack);
//	PlayerInputComponent->BindAction(TEXT("LookBack"), IE_Released, this, &AHSW_Player::LookForward);
}

void AHSW_Player::onMyActionLookBack()
{
	bCanLookBack = !bCanLookBack;
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("onMyActionLookBack"));
}

void AHSW_Player::TurnBack()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("TurnBack"));
	FRotator newRotation = FRotator(0.f, 90.f, 0.f);
	GetMesh()->SetRelativeRotation(newRotation);
//	SetActorRotation(newRotation);


}

void AHSW_Player::LookForward()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("LookForward"));
	FRotator defaultRotation = FRotator(0.f, -90.f, 0.f);
	GetMesh()->SetRelativeRotation(defaultRotation);
//	SetActorRotation(defaultRotation);
}

void AHSW_Player::SetMakeSoundTime()
{
	//float randValue = FMath::FRandRange()
}

// void AHSW_Player::StartUDPServer()
// {
// 	FIPv4Address ip;
// 	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("StartUDPServer"));
// 	if (!FIPv4Address::Parse(TEXT("172.16.17.12"), ip))
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Invalid IP Address"));
// 		return;
// 	}
// 
// 	TSharedPtr<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
// 	addr->SetIp(ip.Value);
// 	addr->SetPort(3333);
// 
// 	FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("UDP Server"), false);
// 	if (!Socket)
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Failed to create socket"));
// 		return;
// 	}
// 
// 	bool result = Socket->Bind(*addr);
// 	if (result)
// 	{
// 		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("UDP Server Started at 172.16.17.12:3333"));
// 		UE_LOG(LogTemp, Warning, TEXT("UDP Server Started at 172.16.17.12:3333"));
// 
// 		uint32 Size;
// 		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("%d"), Socket->HasPendingData(Size)));
// 		while (Socket->HasPendingData(Size))
// 		{
// 			TArray<uint8> ReceivedData;
// 			ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
// 			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("whileloop"));
// 
// 			int32 BytesRead = 0;
// 			if (Socket->Recv(ReceivedData.GetData(), ReceivedData.Num(), BytesRead))
// 			{
// 				// 수신된 데이터를 처리
// 				FString ReceivedString = FString(UTF8_TO_TCHAR(ReceivedData.GetData()));
// 				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, ReceivedString);
// 				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("ReceivedString"));
// 			}
// 			else
// 			{
// 				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Failed to receive data"));
// 			}
// 		}
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Binding failed"));
// 	}
// 
// 	Socket->Close();  // 소켓 닫기
// 	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);  // 소켓 해제
// }

// void AHSW_Player::CreateClient()
// {
// 	// 클라이언트 소켓 생성
// 	ClientSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("TCP Client"), false);
// 	ServerAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
// 
// 
// 	// 서버 IP와 포트 설정
// 	FIPv4Address Ip;
// 	FIPv4Address::Parse(serverIP, Ip); // 서버의 IP 주소 (예: localhost)
// 	ServerAddr->SetIp(Ip.Value); // IP 주소 설정
// 	ServerAddr->SetPort(serverPort); // 서버 포트:
// 
// 
// 	// 서버에 연결
// 	FString connStr = ClientSocket->Connect(*ServerAddr) ? TEXT("Sever Connected") : TEXT("Sever Failed.");
// 
// 
// 	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("%s"), *connStr));
// }
// 
// void AHSW_Player::ReceiveData()
// {
// 	if (ClientSocket)
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, -1.f, FColor::Green, TEXT("Exist Socket"));
// 
// 
// 		// 데이터 있으면 가져오기
// 		uint32 Size;
// 		GEngine->AddOnScreenDebugMessage(-1, -1.f, FColor::Green, FString::Printf(TEXT("%d"), ClientSocket->HasPendingData(Size)));
// 		while (ClientSocket->HasPendingData(Size))
// 		{
// 			TArray<uint8> ReceivedData;
// 			ReceivedData.SetNumUninitialized(FMath::Min(Size, 1024u));
// 
// 
// 			// 데이터 수신
// 			int32 BytesRead = 0;
// 			ClientSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), BytesRead);
// 			// 논블락, 이벤트 드리븐, 
// 
// 			FString ReceivedString = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(ReceivedData.GetData())));
// 			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("jk_____Received: %s"), *ReceivedString));
// 			// @@ 이 데이터를 사용하기
// 
// 		}
// 	}
// 	else
// 	{
// 		GEngine->AddOnScreenDebugMessage(-1, -1.f, FColor::Green, TEXT("No Socket"));
// 	}
// 
// }

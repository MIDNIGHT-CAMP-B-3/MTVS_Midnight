// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HSW_Player.generated.h"

UCLASS()
class MTVS_MIDNIGHT_API AHSW_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHSW_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* PlayerStaticMesh;

	FRotator DefaultRotation = FRotator(0,-90.f,0);
	FRotator LookBackRotation = FRotator(0, 90.f, 0);

	void onMyActionLookBack();

	bool bCanLookBack;

	bool bPlayingQuiz;

	void TurnBack();
	void LookForward();

	//void StartUDPServer();

	// 클라이언트 소켓
    FSocket* ClientSocket;
    // 서버 주소
    TSharedPtr<FInternetAddr> ServerAddr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default|Values")
	FString serverIP = TEXT("192.168.1.87");//TEXT("127.0.0.1");
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default|Values")
	int32 serverPort = 3333;

// 	UFUNCTION(BlueprintCallable)
// 	// 서버와 연결하기
//     void CreateClient();
//     // 데이터 받기
//     UFUNCTION(BlueprintCallable)
//     void ReceiveData();

	float CurrentTime;
	float MakeSoundTime = 2.f;

	bool bCanPlayingSound = true;
	
 	UPROPERTY(EditDefaultsOnly)
 	UAudioComponent* MugungHwuaAudioComponent;

 	UPROPERTY(EditDefaultsOnly)
 	UAudioComponent* CheckAudioComponent;
// 
// 	UPROPERTY(EditDefaultsOnly)
// 	class UParticleSystem* MugungHwuaSoundFactory;

	UPROPERTY(EditDefaultsOnly)
	class USoundBase* MugunghwuaSFV;


	void SetMakeSoundTime();

};

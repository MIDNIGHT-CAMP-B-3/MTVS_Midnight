// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIChildCharacterSpawner.generated.h"

UCLASS()
class MTVS_MIDNIGHT_API AAIChildCharacterSpawner : public AActor
{
	GENERATED_BODY()
	bool bCanLookBack;
	bool bGameStart;
	class AAIChildCharacter* characterAI1;
	class AAIChildCharacter* characterAI2;
	class AAIChildCharacter* characterAI3;
	class AAIChildCharacter* characterAI4;
	class AHSW_Player* player;
public:	
	// Sets default values for this actor's properties
	AAIChildCharacterSpawner();
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AAIChildCharacter> aiChildCharacterFactory;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetStart();
	void CheckSpeed(int32 numAI);
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    USkeletalMesh* NewSkeletalMesh1;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    USkeletalMesh* NewSkeletalMesh2;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
    USkeletalMesh* NewSkeletalMesh3;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

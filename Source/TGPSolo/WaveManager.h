// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaveManager.generated.h"

UCLASS()
class TGPSOLO_API AWaveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Functions
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnEnemy();

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wave)
	int currentWave; //Display on game over
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Wave)
	int waveCount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timer)
	float currentTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timer)
	float respawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	int score; //Display on game over

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	int enemiesKilled; //Display on game over

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	float gameTime; //Display on game over
};

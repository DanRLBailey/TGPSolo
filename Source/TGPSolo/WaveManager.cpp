// Fill out your copyright notice in the Description page of Project Settings.

#include "WaveManager.h"


// Sets default values
AWaveManager::AWaveManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentWave = 1;
	waveCount = 0;
	respawnTime = 2;
	currentTime = respawnTime;
	score = 0;
	enemiesKilled = 0;
	gameTime = 0.0f;
}

// Called when the game starts or when spawned
void AWaveManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	currentTime += DeltaTime;
	gameTime += DeltaTime;

	if (currentTime >= respawnTime)
	{
		currentTime = 0;

		if (waveCount < currentWave)
		{
			waveCount++;
			SpawnEnemy();
		}
	}
}


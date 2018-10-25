// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupSpawnerBase.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APickupSpawnerBase::APickupSpawnerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create & Setup Root Component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AddLocalOffset(FVector(0.0f, 0.0f, 1.0f));

	spawnTimer = 5.0f;
	gameTime = 0;
}

// Called when the game starts or when spawned
void APickupSpawnerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupSpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	gameTime += DeltaTime;

	if (gameTime >= spawnTimer)
	{
		gameTime = 0;
		SpawnPickup();
	}
}


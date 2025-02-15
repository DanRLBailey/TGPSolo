// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawnerBase.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AEnemySpawnerBase::AEnemySpawnerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create & Setup Root Component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AddLocalOffset(FVector(0.0f, 0.0f, 1.0f));
}

// Called when the game starts or when spawned
void AEnemySpawnerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


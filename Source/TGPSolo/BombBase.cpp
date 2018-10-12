// Fill out your copyright notice in the Description page of Project Settings.

#include "BombBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABombBase::ABombBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create & Setup Root Component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	bombTimer = 0.0f;
	bombDestroyTime = 1.0f;
}

// Called when the game starts or when spawned
void ABombBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABombBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bombTimer += DeltaTime;

	if (bombTimer >= bombDestroyTime)
	{
		Explode();
		Destroy();
	}
}


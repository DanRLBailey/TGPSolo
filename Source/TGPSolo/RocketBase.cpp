// Fill out your copyright notice in the Description page of Project Settings.

#include "RocketBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARocketBase::ARocketBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create & Setup Root Component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	rocketTimer = 0.0f;
	rocketDestroyTime = 1.5f;
}

// Called when the game starts or when spawned
void ARocketBase::BeginPlay()
{
	Super::BeginPlay();
	Mesh->AddLocalOffset(FVector(150.0f, 0.0f, 0.0f));
}

// Called every frame
void ARocketBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	rocketTimer += DeltaTime;

	Mesh->AddLocalOffset(FVector(10.0f, 0.0f, 0.0f));

	if (rocketTimer >= rocketDestroyTime)
	{
		Explode();
	}
}


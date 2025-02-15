// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABulletBase::ABulletBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create & Setup Root Component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	bulletTimer = 0.0f;
	bulletDestroyTime = 1.0f;
}

// Called when the game starts or when spawned
void ABulletBase::BeginPlay()
{
	Super::BeginPlay();
	Mesh->AddLocalOffset(FVector(100.0f, 0.0f, 0.0f));
}

// Called every frame
void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bulletTimer += DeltaTime;

	Mesh->AddLocalOffset(FVector(10.0f, 0.0f, 0.0f));

	if (bulletTimer >= bulletDestroyTime)
	{
		Destroy();
	}
}


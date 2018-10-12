// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyBase.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create & Setup Root Component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	health = 1;
	fireTime = 1;
	gameTime = 0;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	gameTime += DeltaTime;
	MoveToPlayer();

	if (gameTime >= fireTime)
	{
		gameTime = 0;
		FireWeapon();
	}
	
	//Check For Death
	if (health <= 0)
	{
		Destroy();
	}
}
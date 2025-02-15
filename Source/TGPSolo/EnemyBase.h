// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

UCLASS()
class TGPSOLO_API AEnemyBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintImplementableEvent)
	void FireWeapon();

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToPlayer();

	UFUNCTION(BlueprintImplementableEvent)
	void CheckForDeath();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Health)
	float health;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
	float fireTime;

	float gameTime;
};

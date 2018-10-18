// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RocketBase.generated.h"

UCLASS()
class TGPSOLO_API ARocketBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocketBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintImplementableEvent)
	void Explode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletTimers)
	float rocketTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BulletTimers)
	float rocketDestroyTime;
	
};

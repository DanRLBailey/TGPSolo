// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TGPSOLO_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	UPROPERTY(EditAnywhere)
	USceneComponent* VisibleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCapsuleComponent* Root;

	//Input Functions
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void Jump();

	//Input Variables
	FVector currentVelocity;
	float velocityMultiplier;
	bool canJump;
	float gameTime;
	float currentTime;
	float jumpTimer;
};

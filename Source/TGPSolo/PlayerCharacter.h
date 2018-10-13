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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* PlayerCamera;

	UFUNCTION(BlueprintImplementableEvent)
	void ChangeWeapon();

	UFUNCTION(BlueprintImplementableEvent)
	void FireWeapon();

	//Input Functions
	void Jump();
	void MoveUpPressed();
	void MoveDownPressed();
	void MoveLeftPressed();
	void MoveRightPressed();
	void MoveUpReleased();
	void MoveDownReleased();
	void MoveLeftReleased();
	void MoveRightReleased();

	//Input Variables
	FVector currentVelocity;
	float velocityMultiplier;
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;

	bool canJump;
	float gameTime;
	float currentTime;
	float jumpTimer;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon)
	int currentWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Weapon)
	TArray<int> weaponArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Health)
	float health;

	bool canFire;
};

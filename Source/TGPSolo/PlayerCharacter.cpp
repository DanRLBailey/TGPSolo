// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Auto Possess
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Create & Setup Root Component
	Root = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root"));
	Root->SetSimulatePhysics(true);
	Root->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Root->SetRelativeLocation(FVector(0.0f, 0.0f, 44.0f));
	Root->GetBodyInstance()->bLockXRotation = true;
	Root->GetBodyInstance()->bLockYRotation = true;
	Root->GetBodyInstance()->bLockZRotation = true;

	//Create Camera and Visible Object
	UCameraComponent* PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));

	//Attach to root and offset camera
	PlayerCamera->SetupAttachment(Root);
	PlayerCamera->SetRelativeLocation(FVector(-500.0f, 0.0f, 500.0f));
	PlayerCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	VisibleComponent->SetupAttachment(Root);
	VisibleComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -44.0f));

	//Initialise Variables
	velocityMultiplier = 100.0f;
	gameTime = 0.0f;
	currentTime = 0.0f;
	jumpTimer = 1.0f;
	canJump = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	gameTime += DeltaTime;

	if (!currentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (currentVelocity * DeltaTime);
		SetActorLocation(NewLocation);

		if (velocityMultiplier <= 1000.0)
		{
			velocityMultiplier += 10;
		}
	}
	else
	{
		velocityMultiplier = 100.0;
	}

	if (gameTime >= (currentTime + jumpTimer))
	{
		canJump = true;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &APlayerCharacter::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &APlayerCharacter::Move_YAxis);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::Move_XAxis(float AxisValue)
{
	//Move at 100 units/s forward or backward
	currentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * velocityMultiplier;
}

void APlayerCharacter::Move_YAxis(float AxisValue)
{
	//Move at 100 units/s right or left
	currentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * velocityMultiplier;
}

void APlayerCharacter::Jump()
{
	if (canJump)
	{
		canJump = false;
		Root->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, 500.0f));

		if (gameTime >= (currentTime + jumpTimer))
		{
			currentTime = gameTime;
		}
	}
}
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
	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	Ball->SetSimulatePhysics(true);
	Ball->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Ball->SetRelativeLocation(FVector(0.0f, 0.0f, 44.0f));

	//Create Spring Arm and Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(Ball);
	CameraBoom->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	CameraBoom->TargetArmLength = 1200.0f;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraBoom);
	

	//Initialise Variables
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;
	velocityMultiplier = 100.0f;

	gameTime = 0.0f;
	currentTime = 0.0f;
	jumpTimer = 1.0f;
	canJump = true;

	currentWeapon = 0;
	weaponArray = { 0, 1, 2, 3 };
	canFire = true;

	health = 1;
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

	//Movement
	{
		if (moveUp)
		{
			Ball->AddImpulse(FVector(3000.0f, 0.0f, 0.0f));
		}

		if (moveDown)
		{
			Ball->AddImpulse(FVector(-3000.0f, 0.0f, 0.0f));
		}

		if (moveLeft)
		{
			Ball->AddImpulse(FVector(0.0f, -3000.0f, 0.0f));
		}

		if (moveRight)
		{
			Ball->AddImpulse(FVector(0.0f, 3000.0f, 0.0f));
		}

		if (gameTime >= (currentTime + jumpTimer))
		{
			canJump = true;
		}
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerCharacter::MoveUpPressed);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerCharacter::MoveDownPressed);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerCharacter::MoveLeftPressed);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerCharacter::MoveRightPressed);
	InputComponent->BindAction("MoveUp", IE_Released, this, &APlayerCharacter::MoveUpReleased);
	InputComponent->BindAction("MoveDown", IE_Released, this, &APlayerCharacter::MoveDownReleased);
	InputComponent->BindAction("MoveLeft", IE_Released, this, &APlayerCharacter::MoveLeftReleased);
	InputComponent->BindAction("MoveRight", IE_Released, this, &APlayerCharacter::MoveRightReleased);
}

void APlayerCharacter::Jump()
{
	if (canJump)
	{
		canJump = false;
		Ball->AddImpulse(FVector(0.0f, 0.0f, 50000.0f));

		if (gameTime >= (currentTime + jumpTimer))
		{
			currentTime = gameTime;
		}
	}
}

void APlayerCharacter::MoveUpPressed()
{
	moveUp = true;
}

void APlayerCharacter::MoveDownPressed()
{
	moveDown = true;
}

void APlayerCharacter::MoveLeftPressed()
{
	moveLeft = true;
}

void APlayerCharacter::MoveRightPressed()
{
	moveRight = true;
}

void APlayerCharacter::MoveUpReleased()
{
	moveUp = false;
}

void APlayerCharacter::MoveDownReleased()
{
	moveDown = false;
}

void APlayerCharacter::MoveLeftReleased()
{
	moveLeft = false;
}

void APlayerCharacter::MoveRightReleased()
{
	moveRight = false;
}
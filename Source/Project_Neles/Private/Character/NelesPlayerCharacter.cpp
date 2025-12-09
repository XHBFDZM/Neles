// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NelesPlayerCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Controller/NelesPlayerController.h"
#include "Input/NelesInputComponent.h"
#include <../../../../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/InputActionValue.h>

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Character/NelesCameraComponent.h"

ANelesPlayerCharacter::ANelesPlayerCharacter()
{
	USceneComponent* RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	
	NelesInputComponent = CreateDefaultSubobject<UNelesInputComponent>(TEXT("NelesInputComponent"));

	NelesCameraComponent = CreateDefaultSubobject<UNelesCameraComponent>(TEXT("NelesCameraComponent"));
	NelesCameraComponent->SetupAttachment(GetCapsuleComponent());

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(NelesCameraComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;
}

void ANelesPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (UNelesInputComponent* InputComp = this->NelesInputComponent)
	{
		InputComp->MoveEventSignature.AddDynamic(this, &ANelesPlayerCharacter::Move);
		InputComp->WatchEventSignature.AddDynamic(this, &ANelesPlayerCharacter::Watch);
	}
}

void ANelesPlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2d MoveValue = Value.Get<FVector2d>();
	FRotator3d ControlRotation = GetControlRotation();
	FRotator3d YawRotation = FRotator3d(0, ControlRotation.Yaw, 0);
	FVector3d ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector3d RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, MoveValue.Y);
	AddMovementInput(RightDirection, MoveValue.X);
	return;
}
void ANelesPlayerCharacter::Watch(const FInputActionValue& Value)
{
	const FVector2d WatchValue = Value.Get<FVector2d>();
	if (ANelesPlayerController* NelesPC = Cast<ANelesPlayerController>(GetController()))
	{
		NelesPC->AddYawInput(WatchValue.X);
		NelesPC->AddPitchInput(WatchValue.Y);
	}
	return;
}



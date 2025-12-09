// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/NelesPlayerController.h"

#include "Input/NelesInputComponent.h"
#include "Input/NelesInputMappingData.h"
#include "EnhancedInputComponent.h"
#include "Character/NelesPlayerCharacter.h"
#include <../../../../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h>

ANelesPlayerController::ANelesPlayerController()
{
	this->SetGenericTeamId(FGenericTeamId(1));
}

void ANelesPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ANelesPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer) return;
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!Subsystem) return;
	//Ĭ�IMC
	UInputMappingContext* InputMappingContext = NelesInputMappingData->DefaultInputMappingContext;
	if (!InputMappingContext) return;
	Subsystem->AddMappingContext(InputMappingContext, 0);
}

void ANelesPlayerController::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);

	ANelesPlayerCharacter* NelesPlayerCharacter = Cast<ANelesPlayerCharacter>(aPawn);
	if (!NelesPlayerCharacter) {
		return;
	}
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	NelesPlayerCharacter->NelesInputComponent->BindInputEvent(EnhancedInputComponent);
}

void ANelesPlayerController::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	if (TeamID != NewTeamID)
	{
		TeamID = NewTeamID;
	}
}


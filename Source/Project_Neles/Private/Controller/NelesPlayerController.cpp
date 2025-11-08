// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/NelesPlayerController.h"

#include "Input/NelesInputComponent.h"
#include "Input/NelesInputMappingData.h"
#include "EnhancedInputComponent.h"
#include "Character/NelesPlayerCharacter.h"
#include <../../../../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h>

ANelesPlayerController::ANelesPlayerController()
{

}

void ANelesPlayerController::BeginPlay()
{

}

void ANelesPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer) return;
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!Subsystem) return;
	//Ä¬ÈÏIMC
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


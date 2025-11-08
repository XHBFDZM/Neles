// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/NelesInputComponent.h"
#include "EnhancedInputComponent.h"
#include <EnhancedInput/Public/InputActionValue.h>

// Sets default values for this component's properties
UNelesInputComponent::UNelesInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNelesInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNelesInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNelesInputComponent::BindInputEvent(UEnhancedInputComponent* EnhancedInputComponent) {
	if (!EnhancedInputComponent) {
		return;
	}	
	EnhancedInputComponent->BindAction(this->IA_Move, ETriggerEvent::Triggered, this, &UNelesInputComponent::MoveEvent);
	EnhancedInputComponent->BindAction(this->IA_Watch, ETriggerEvent::Triggered, this, &UNelesInputComponent::WatchEvent);
}

void UNelesInputComponent::MoveEvent(const FInputActionValue& Value)
{
	MoveEventSignature.Broadcast(Value);
}
void UNelesInputComponent::WatchEvent(const FInputActionValue& Value)
{
	WatchEventSignature.Broadcast(Value);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NelesCharacterBase.h"

// Sets default values
ANelesCharacterBase::ANelesCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANelesCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANelesCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANelesCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_NelesGameMode.h"
#include "Project_NelesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_NelesGameMode::AProject_NelesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

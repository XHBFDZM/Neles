// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "NelesEnemyAIPerceptionComponent.generated.h"



class UAISenseConfig_Sight;
/**
 * 
 */
UCLASS()
class PROJECT_NELES_API UNelesEnemyAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	UNelesEnemyAIPerceptionComponent();
protected:
	virtual void BeginPlay() override;

};

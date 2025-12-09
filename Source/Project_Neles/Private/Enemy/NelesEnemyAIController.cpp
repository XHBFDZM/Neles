// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/NelesEnemyAIController.h"
#include "Enemy/NelesEnemyAIPerceptionComponent.h"
#include "Enemy/AIContextComponent.h"
#include "Components/StateTreeAIComponent.h"
#include "Components/StateTreeComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ANelesEnemyAIController::ANelesEnemyAIController()
{
	this->SetGenericTeamId(FGenericTeamId(2));
	this->StateTreeAIComponent = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeComponent"));
	this->AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	this->AIContextComponent = CreateDefaultSubobject<UAIContextComponent>(TEXT("AIContextComponent"));
	this->SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 3000.f;
	SightConfig->LoseSightRadius = 3500.f;
	SightConfig->PeripheralVisionAngleDegrees = 180.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	AIPerceptionComponent->ConfigureSense(*SightConfig);
	AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void ANelesEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	UAIPerceptionComponent* const AIPerceptionCom = this->GetAIPerceptionComponent();
	if(AIPerceptionCom)
		AIPerceptionCom->OnTargetPerceptionUpdated.AddDynamic(this, &ANelesEnemyAIController::OnTargetActorUpdated);
}


void ANelesEnemyAIController::OnTargetActorUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (this->StateTreeAIComponent)
	{  
		AIContextComponent->TargetActor = Actor;
	}
}
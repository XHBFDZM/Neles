// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NelesEnemyAIController.generated.h"

class UStateTreeAIComponent;
class UAIPerceptionComponent;
class UAIContextComponent;
class UAISenseConfig_Sight;
struct FAIStimulus;

UCLASS()
class PROJECT_NELES_API ANelesEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	ANelesEnemyAIController();
protected:
	virtual void BeginPlay() override;
private:
	UFUNCTION()
	void OnTargetActorUpdated(AActor* Actor, FAIStimulus Stimulus);
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStateTreeAIComponent> StateTreeAIComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAIContextComponent> AIContextComponent;
private:
	UPROPERTY()
	TObjectPtr<UAISenseConfig_Sight> SightConfig = nullptr;
};

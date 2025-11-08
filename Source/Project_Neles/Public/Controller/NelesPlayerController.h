// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NelesPlayerController.generated.h"


class UNelesInputComponent;
class UNelesInputMappingData;
/**
 * 
 */
UCLASS()
class PROJECT_NELES_API ANelesPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ANelesPlayerController();
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNelesInputMappingData> NelesInputMappingData;

	virtual void SetupInputComponent() override;
public:
	void OnPossess(APawn* aPawn) override;
};

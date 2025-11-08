// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "EnhancedInput/Public/InputMappingContext.h"

#include "NelesInputMappingData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PROJECT_NELES_API UNelesInputMappingData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input Mapping")
	TObjectPtr<UInputMappingContext> DefaultInputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TArray<UInputMappingContext*> ExtraContexts;
};

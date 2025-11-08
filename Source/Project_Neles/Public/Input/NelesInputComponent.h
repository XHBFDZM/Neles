// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NelesInputComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMoveEventSignature, const FInputActionValue&, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWatchEventSignature, const FInputActionValue&, Value);

class UInputAction;
class UEnhancedInputComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_NELES_API UNelesInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNelesInputComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	void BindInputEvent(UEnhancedInputComponent* EnhancedInputComponent);
private:
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Move;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Watch;
public:
	UPROPERTY(BlueprintAssignable, Category = "Input|Events")
	FMoveEventSignature MoveEventSignature;
	UPROPERTY(BlueprintAssignable, Category = "Input|Events")
	FWatchEventSignature WatchEventSignature;
private:
	UFUNCTION()
	void MoveEvent(const FInputActionValue& Value);
	UFUNCTION()
	void WatchEvent(const FInputActionValue& Value);
};

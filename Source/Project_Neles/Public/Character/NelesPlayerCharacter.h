// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/NelesCharacterBase.h"
#include "NelesPlayerCharacter.generated.h"


class UNelesInputComponent;
class UNelesCameraComponent;
class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class PROJECT_NELES_API ANelesPlayerCharacter : public ANelesCharacterBase
{
	GENERATED_BODY()
public:
	ANelesPlayerCharacter();
protected:
	void BeginPlay();
public:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UNelesInputComponent> NelesInputComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNelesCameraComponent> NelesCameraComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
public:
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Watch(const FInputActionValue& Value);
};

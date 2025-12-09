// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NelesEnemySubsystem.generated.h"

UENUM()
enum class EEnemyState : uint8
{
	Idle = 0,
	WalkAroundWithTarget = 1,
	Attack = 2,
	Hit = 3,
	Dead = 4,
};

USTRUCT()
struct FEnemyData
{
	GENERATED_BODY()
public:
	UPROPERTY()
	int32 Health;
	UPROPERTY()
	int32 Damage;
	UPROPERTY()
	FVector3d Velocity;
	UPROPERTY()
	EEnemyState CurrentState;
	FEnemyData()
		: Health(100)
		, Damage(10)
		, Velocity(FVector3d::ZeroVector)
		, CurrentState(EEnemyState::Idle)
	{
	}
};
/**
 * 
 */
UCLASS()
class PROJECT_NELES_API UNelesEnemySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
private:
	TArray< FEnemyData> EnemyDataArray;
public:
	int32 CreateEnemy();
	bool KillEnemy(int32 EnemyEntity);
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;
};

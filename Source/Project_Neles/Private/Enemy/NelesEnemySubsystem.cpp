// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/NelesEnemySubsystem.h"

int32 UNelesEnemySubsystem::CreateEnemy()
{
	int32 EnemyEntity = this->EnemyDataArray.Add(FEnemyData());
	return EnemyEntity;
}

bool UNelesEnemySubsystem::KillEnemy(int32 EnemyEntity)
{
	if(this->EnemyDataArray.IsValidIndex(EnemyEntity))
	{
		this->EnemyDataArray[EnemyEntity].CurrentState = EEnemyState::Dead;
		return true;
	}
	return false;
}

void UNelesEnemySubsystem::Initialize(FSubsystemCollectionBase& Collection) {

}

void UNelesEnemySubsystem::Deinitialize() {

}
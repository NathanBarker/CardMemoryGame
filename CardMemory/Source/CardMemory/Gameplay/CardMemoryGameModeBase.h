// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardMemory/GameData/CardModel.h"
#include "GameFramework/GameModeBase.h"
#include "ModelViewViewModel/Public/MVVMSubsystem.h"
#include "CardMemoryGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDMEMORY_API ACardMemoryGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void StartPlay() override;
	virtual void ResetLevel() override;

	void StartNextLevel();

private:
	UPROPERTY()
	TObjectPtr<UMVVMSubsystem> ViewModelSubsystem = nullptr;

	int32 CurrentGameLevel = 0;
};

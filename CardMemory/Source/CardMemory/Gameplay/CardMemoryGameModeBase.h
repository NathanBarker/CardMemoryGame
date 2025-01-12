// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "ModelViewViewModel/Public/MVVMSubsystem.h"

#include "CardMemoryGameModeBase.generated.h"

CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UIMessagePopulateCards);

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

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

private:
	UPROPERTY()
	TObjectPtr<UMVVMSubsystem> ViewModelGameSubsystem = nullptr;

	int32 CurrentGameLevel = 0;

	// TODO: Move to developer settings
	int32 CardAmount = 8;
};

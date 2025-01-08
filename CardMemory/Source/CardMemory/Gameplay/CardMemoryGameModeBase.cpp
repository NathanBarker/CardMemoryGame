// Fill out your copyright notice in the Description page of Project Settings.


#include "CardMemoryGameModeBase.h"

void ACardMemoryGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	ViewModelSubsystem = GEngine->GetEngineSubsystem<UMVVMSubsystem>();
	check(ViewModelSubsystem);

	if(IsValid(ViewModelSubsystem))
	{
		UE_LOG(LogTemp, Warning, TEXT("Sucessfully got the MVVM Subsystem"));
	}
}

void ACardMemoryGameModeBase::StartPlay()
{
	Super::StartPlay();
}

void ACardMemoryGameModeBase::ResetLevel()
{
	Super::ResetLevel();
}

void ACardMemoryGameModeBase::StartNextLevel()
{
}

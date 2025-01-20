// Fill out your copyright notice in the Description page of Project Settings.


#include "CardMemoryGameModeBase.h"

#include "MVVMGameSubsystem.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"

UE_DEFINE_GAMEPLAY_TAG(UIMessagePopulateCards, "UIMessagePopulateCards");

void ACardMemoryGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	const UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	check(GameInstance);

	UMVVMGameSubsystem* ViewModelGameSubsystem = GameInstance->GetSubsystem<UMVVMGameSubsystem>();
	check(ViewModelGameSubsystem);

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	check(MessageSubsystem);

	if (!IsValid(ViewModelGameSubsystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the MVVM Subsystem"));
	}

	UMVVMViewModelCollectionObject* GlobalViewModelCollection = GameInstance->GetSubsystem<UMVVMGameSubsystem>()->
	                                                                          GetViewModelCollection();
	check(GlobalViewModelCollection);

	// Todo: Create a level View model that contains an array of CardViewmodels that the MainScreen can iterate over

	FMVVMViewModelContext LevelVMContext = FMVVMViewModelContext();
	LevelVMContext.ContextClass = UCardLevelViewModel::StaticClass();
	LevelVMContext.ContextName = FName(GetNameSafe(UCardLevelViewModel::StaticClass()));
	CardLevelViewModel = NewObject<UCardLevelViewModel>();
	GlobalViewModelCollection->AddViewModelInstance(LevelVMContext, CardLevelViewModel);
}

void ACardMemoryGameModeBase::StartPlay()
{
	Super::StartPlay();
}

void ACardMemoryGameModeBase::ResetLevel()
{
	Super::ResetLevel();
}
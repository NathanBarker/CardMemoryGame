// Fill out your copyright notice in the Description page of Project Settings.


#include "CardMemoryGameModeBase.h"

#include "MVVMGameSubsystem.h"
#include "CardMemory/ViewModels/CardViewModel.h"

void ACardMemoryGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	const UGameInstance* GameInstance = GetWorld()->GetGameInstance();
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

	FMVVMViewModelContext CardVMContext = FMVVMViewModelContext();
	CardVMContext.ContextClass = UCardViewModel::StaticClass();
	CardVMContext.ContextName = FName(GetNameSafe(UCardViewModel::StaticClass()));

	GlobalViewModelCollection->AddViewModelInstance(CardVMContext, NewObject<UCardViewModel>());
}

void ACardMemoryGameModeBase::StartPlay()
{
	Super::StartPlay();

	UE_LOG(LogTemp, Warning, TEXT("here"));

	// TDOD: Create card data here and send to the main screen via gameplaymessages
}

void ACardMemoryGameModeBase::ResetLevel()
{
	Super::ResetLevel();
}

void ACardMemoryGameModeBase::StartNextLevel()
{
}

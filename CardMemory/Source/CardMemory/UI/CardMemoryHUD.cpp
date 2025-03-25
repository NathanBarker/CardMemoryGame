// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardMemoryHUD.h"

#include "CardMemory/Gameplay/GameController.h"
#include "CardMemory/SlateUI/CardMemoryText.h"
#include "CardMemory/SlateUI/CardMemoryImage.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "MVVMGameSubsystem.h"

void ACardMemoryHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	const UGameInstance* GameInstance = GetGameInstance();

	if (!IsValid(GameInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the Game Instance"));
		return;
	}

	UMVVMGameSubsystem* ViewModelGameSubsystem = GameInstance->GetSubsystem<UMVVMGameSubsystem>();
	check(ViewModelGameSubsystem);

	if (!IsValid(ViewModelGameSubsystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the MVVM Subsystem"));
		return;
	}

	UMVVMViewModelCollectionObject* GlobalViewModelCollection = ViewModelGameSubsystem->GetViewModelCollection();
	check(GlobalViewModelCollection);

	if (!IsValid(GlobalViewModelCollection))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the GlobalViewModelCollection"));
		return;
	}

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	check(MessageSubsystem);

	if (!IsValid(MessageSubsystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the MessageSubsystem"));
		return;
	}

	FMVVMViewModelContext LevelVMContext = FMVVMViewModelContext();
	LevelVMContext.ContextClass = UCardLevelViewModel::StaticClass();
	LevelVMContext.ContextName = FName(GetNameSafe(UCardLevelViewModel::StaticClass()));
	CardLevelViewModel = NewObject<UCardLevelViewModel>();
	GlobalViewModelCollection->AddViewModelInstance(LevelVMContext, CardLevelViewModel);
}

void ACardMemoryHUD::BeginPlay()
{
	Super::BeginPlay();

	// TODO: Sort out creating a deck based on the level being played
	APlayerController* PlayerController = GetOwningPlayerController();
	if (!IsValid(PlayerController))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the Player Controller"));
		return;
	}

	AGameController* Controller = Cast<AGameController>(PlayerController);
	GameController = Controller;
	check(GameController);

	if (!IsValid(CardLevelViewModel))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the CardLevelViewModel"));
	}

	GameController->AssignLevelViewModel(CardLevelViewModel);
	CardLevelViewModel->SetCardViewModels(GameController->CreateDeck(0));

	TimerText = SNew(SCardMemoryText);
	Background = SNew(SCardMemoryImage).Brush(&BackgroundImage);
	DarkBackground = SNew(SCardMemoryImage).Brush(&DarkernBackgroundImage);

	GEngine->GameViewport->AddViewportWidgetContent(TimerText.ToSharedRef(), HeaderTextZOrder);
	GEngine->GameViewport->AddViewportWidgetContent(Background.ToSharedRef(), 0);
	GEngine->GameViewport->AddViewportWidgetContent(DarkBackground.ToSharedRef(), 0);
}

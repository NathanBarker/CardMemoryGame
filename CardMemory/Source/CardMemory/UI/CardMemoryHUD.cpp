// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardMemoryHUD.h"
#include "MVVMGameSubsystem.h"
#include "CardMemory/Gameplay/GameController.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"

UE_DEFINE_GAMEPLAY_TAG(UIMessagePopulateCards, "UIMessagePopulateCards");

void ACardMemoryHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	const UGameInstance* GameInstance = GetGameInstance();
	check(GameInstance);

	UMVVMGameSubsystem* ViewModelGameSubsystem = GameInstance->GetSubsystem<UMVVMGameSubsystem>();
	check(ViewModelGameSubsystem);

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	check(MessageSubsystem);

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

	CardLevelViewModel->SetCardViewModels(GameController->CreateDeck(0));
}

// // Nathan Barker Card Memory Game Personal Training Project. 

#include "GameController.h"

#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "CardMemory/ViewModels/CardViewModel.h"
#include "MVVMGameSubsystem.h"

TArray<UCardViewModel*> AGameController::CreateDeck(const int32 Level)
{
	// First pass. todo: use a map of level state to control how many cards get made
	// Level 0 will have 6 cards, 3 pairs. When one card vm gets created with random data, we should copy it and add it to the list
	// Once the desired amount has been created, set them in the LevelViewModel array

	const UGameInstance* GameInstance = GetGameInstance();
	check(GameInstance);

	UMVVMGameSubsystem* ViewModelGameSubsystem = GameInstance->GetSubsystem<UMVVMGameSubsystem>();
	check(ViewModelGameSubsystem);

	UMVVMViewModelCollectionObject* GlobalViewModelCollection = GameInstance->GetSubsystem<UMVVMGameSubsystem>()->
	                                                                          GetViewModelCollection();
	check(GlobalViewModelCollection);

	if (!IsValid(ViewModelGameSubsystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the MVVM Subsystem"));
	}

	TArray<UCardViewModel*> CardViewModels = {};

	for (int32 i = 0; i < Level0CardAmount / 2; i++)
	{
		UCardViewModel* CardViewModel = nullptr;
		FMVVMViewModelContext CardVMContext = FMVVMViewModelContext();
		CardVMContext.ContextClass = UCardViewModel::StaticClass();
		CardVMContext.ContextName = FName(GetNameSafe(UCardViewModel::StaticClass()));
		CardViewModel = NewObject<UCardViewModel>();

		// Create Copy
		UCardViewModel* PairedCardViewModel = nullptr;
		FMVVMViewModelContext CardVMPairContext = FMVVMViewModelContext();
		CardVMPairContext.ContextClass = UCardViewModel::StaticClass();
		CardVMPairContext.ContextName = FName(GetNameSafe(UCardViewModel::StaticClass()));
		PairedCardViewModel = NewObject<UCardViewModel>();

		// Set card type
		// TODO: replace magic numbers
		CardViewModel->SetCardIndex(i);
		PairedCardViewModel->SetCardIndex(i + (Level0CardAmount / 2));

		CardViewModel->SetPairIndex(i + (Level0CardAmount / 2));
		PairedCardViewModel->SetPairIndex(i);

		EType CardType = static_cast<EType>(rand() % 3);
		CardViewModel->SetType(CardType);
		PairedCardViewModel->SetType(CardType);

		int32 RandomPatternType = rand() % 3 + 1;
		CardViewModel->SetPatternType(RandomPatternType);
		PairedCardViewModel->SetPatternType(RandomPatternType);
		
		GlobalViewModelCollection->AddViewModelInstance(CardVMContext, CardViewModel);
		GlobalViewModelCollection->AddViewModelInstance(CardVMPairContext, PairedCardViewModel);

		CardViewModels.Emplace(CardViewModel);
		CardViewModels.Emplace(PairedCardViewModel);
	}

	return CardViewModels;
}

void AGameController::BeginPlay()
{
	Super::BeginPlay();
}

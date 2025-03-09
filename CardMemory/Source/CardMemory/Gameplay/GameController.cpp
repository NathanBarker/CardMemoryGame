// // Nathan Barker Card Memory Game Personal Training Project. 

#include "GameController.h"

#include "MVVMGameSubsystem.h"
#include "Algo/RandomShuffle.h"
#include "CardMemory/UI/CardView.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"

UE_DEFINE_GAMEPLAY_TAG(UI_MessageFlipCardsBack, "UI_MessageFlipCardsBack");
UE_DEFINE_GAMEPLAY_TAG(UI_DisableCards, "UI_DisableCards");

TArray<UCardViewModel*> AGameController::CreateDeck(const int32 Level)
{
	// First pass. todo: use a map of level state to control how many cards get made
	// Level 0 will have 6 cards, 3 pairs. When one card vm gets created with random data, we should copy it and add it to the list
	// Once the desired amount has been created, set them in the LevelViewModel array

	AllUsedPatterns.Emplace(CrossPatterns);
	AllUsedPatterns.Emplace(CirclePatterns);
	AllUsedPatterns.Emplace(SquarePatterns);
	AllUsedPatterns.Emplace(TrianglePatterns);

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	check(MessageSubsystem);

	MessageSubsystem->RegisterListener(
		UI_MessageCardSelected, this, &AGameController::CheckFlippedCards);

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
		return {};
	}

	TArray<UCardViewModel*> CardViewModels = {};

	for (int32 i = 0; i < Level0CardAmount / 2; i++)
	{
		UCardViewModel* CardViewModel = NewObject<UCardViewModel>();
		UCardViewModel* PairedCardViewModel = NewObject<UCardViewModel>();

		RandomiseCardData(*CardViewModel, *PairedCardViewModel);

		CardViewModel->SetCardGUID(i);
		PairedCardViewModel->SetCardGUID(i);

		GlobalViewModelCollection->AddViewModelInstance(CreateCardVMContext(), CardViewModel);
		GlobalViewModelCollection->AddViewModelInstance(CreateCardVMContext(), PairedCardViewModel);

		CardViewModels.Emplace(CardViewModel);
		CardViewModels.Emplace(PairedCardViewModel);
	}

	Algo::RandomShuffle(CardViewModels);
	return CardViewModels;
}

void AGameController::AssignLevelViewModel(UCardLevelViewModel* CardLevelViewModel)
{
	LevelViewModel = CardLevelViewModel;
}

void AGameController::CheckFlippedCards(FGameplayTag InChannel, const FGuid& InMessage)
{
	if (!IsValid(MessageSubsystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the GameplayMessage Subsystem"));
		return;
	}

	if (FirstSelectedCardGUID == -1)
	{
		FirstSelectedCardGUID = InMessage.A;
		return;
	}

	if (FirstSelectedCardGUID == InMessage.A && FirstSelectedCardGUID != -1)
	{
		for (UCardViewModel* CardViewModel : LevelViewModel->GetCardViewModels())
		{
			if (CardViewModel->GetCardGUID() == FirstSelectedCardGUID)
			{
				CardViewModel->SetIsRevealed(true);
			}
		}
		FirstSelectedCardGUID = -1;
	}
	else
	{
		OutGoingMessage.A = FirstSelectedCardGUID;
		OutGoingMessage.B = InMessage.A;
		MessageSubsystem->BroadcastMessage(UI_DisableCards, OutGoingMessage);
		GetWorldTimerManager().SetTimer(DelayTimerHandle, this, &AGameController::BroadcastCardResult, 2.0f, false);
	}
}

void AGameController::BroadcastCardResult()
{
	MessageSubsystem->BroadcastMessage(UI_MessageFlipCardsBack, OutGoingMessage);
	FirstSelectedCardGUID = -1;
}

void AGameController::RandomiseCardData(UCardViewModel& CardViewModel, UCardViewModel& PairedCardViewModel)
{
	int32 CardTypeIndex = FMath::RandRange(0, 3);
	EType CardType = static_cast<EType>(CardTypeIndex);
	int32 RandomPatternType = FMath::RandRange(0, 3);

	TArray<int32>& CardPatternContainer = AllUsedPatterns[CardTypeIndex];

	while (!ValidCardEntry)
	{
		if (CardPatternContainer.Num() == 0)
		{
			ValidCardEntry = true;
			break;
		}

		for (const int32& UsedPattern : CardPatternContainer)
		{
			int32* Result = CardPatternContainer.FindByPredicate([&](const int32& InItem)
			{
				return InItem == RandomPatternType;
			});

			if (Result == nullptr)
			{
				ValidCardEntry = true;
				break;
			}

			RandomPatternType = rand() % 3 + 1;
		}
	}

	CardViewModel.SetType(CardType);
	PairedCardViewModel.SetType(CardType);

	CardViewModel.SetPatternType(RandomPatternType);
	PairedCardViewModel.SetPatternType(RandomPatternType);

	CardViewModel.SetIsRevealed(false);
	PairedCardViewModel.SetIsRevealed(false);

	CardPatternContainer.Emplace(RandomPatternType);
	ValidCardEntry = false;
}

FMVVMViewModelContext AGameController::CreateCardVMContext()
{
	FMVVMViewModelContext CardVMContext = FMVVMViewModelContext();
	CardVMContext.ContextClass = UCardViewModel::StaticClass();
	CardVMContext.ContextName = FName(GetNameSafe(UCardViewModel::StaticClass()));
	return CardVMContext;
}

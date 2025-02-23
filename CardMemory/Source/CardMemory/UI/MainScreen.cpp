// // Nathan Barker Card Memory Game Personal Training Project. 

#include "MainScreen.h"
#include "CardMemory/UI/CardMemoryHUD.h"
#include "CardMemory/UI/CardView.h"
#include "CardMemory/UI/CardMemoryButtonBase.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "GameplayTagContainer.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();

	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageSubsystem.RegisterListener(UIMessagePopulateCards, this, &UMainScreen::PopulateDeck);

	WidgetViewModel = GetVM<UCardLevelViewModel>();
	SetViewModel(WidgetViewModel);
}

void UMainScreen::UpdateWidget()
{
	if (!IsValid(WidgetViewModel))
	{
		return;
	}
	// create deck based on the level viewmodel

	int32 CurrentColumn = 0;
	int32 CurrentRow = 0;

	for (UCardViewModel* CardViewModel : WidgetViewModel->GetCardViewModels())
	{
		if (IsValid(CardTemplate))
		{
			UCardMemoryButtonBase* CardView = CreateWidget<UCardMemoryButtonBase>(GetWorld(), CardTemplate);
			CardView->SetViewModel(CardViewModel);
			CardDeck->AddChild(CardView);

			if (!IsValid(CardView->Slot))
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to get the CardView Grid Slot at %d"), CurrentColumn);
			}

			UUniformGridSlot* CardGridSlot = Cast<UUniformGridSlot>(CardView->Slot);

			if (CurrentColumn == ColumnMaxCount)
			{
				CurrentRow++;
				CurrentColumn = 0;
			}

			CardGridSlot->SetRow(CurrentRow);
			CardGridSlot->SetColumn(CurrentColumn);
			CurrentColumn++;
		}
	}
}

void UMainScreen::PopulateDeck(FGameplayTag InChannel, const FCardsMessage& InMessage)
{
}

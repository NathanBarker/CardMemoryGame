// // Nathan Barker Card Memory Game Personal Training Project. 

#include "MainScreen.h"
#include "CardMemory/UI/CardView.h"
#include "CardMemory/UI/CardMemoryButtonBase.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "GameplayTagContainer.h"
#include "CardMemory/Gameplay/GameController.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	check(MessageSubsystem);

	MessageSubsystem->RegisterListener(UI_MessageFlipCardsBack, this, &UMainScreen::FlipCardsBack);
	MessageSubsystem->RegisterListener(UI_DisableCards, this, &UMainScreen::DisableCards);

	WidgetViewModel = GetVM<UCardLevelViewModel>();
	SetViewModel(WidgetViewModel);
}

void UMainScreen::UpdateWidget()
{
	if (!IsValid(WidgetViewModel))
	{
		return;
	}

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
	UCardMemoryButtonBase* FirstCardView = Cast<UCardMemoryButtonBase>(CardDeck->GetChildAt(0));
	FirstCardView->SetFocus();
}

void UMainScreen::FlipCardsBack(FGameplayTag InChannel, const FGuid& InMessage)
{
	for (UWidget* ChildWidget : CardDeck->GetAllChildren())
	{
		if (!IsValid(ChildWidget))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get the child widget from the card deck to flip at"));
			return;
		}
		
		UCardView* CardView = Cast<UCardView>(ChildWidget);
		if (!IsValid(CardView))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get the CardView to flip at"));
			return;
		}
		
		if (!CardView->IsHidden) CardView->HideCard();
		CardView->SetIsInteractionEnabled(true);
	}
}

void UMainScreen::DisableCards(FGameplayTag InChannel, const FGuid& InMessage)
{
	for (UWidget* ChildWidget : CardDeck->GetAllChildren())
	{
		if (!IsValid(ChildWidget))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get the child widget from the card deck to disable"));
			return;
		}
		
		UCardView* CardView = Cast<UCardView>(ChildWidget);
		if (!IsValid(CardView))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get the CardView to disable"));
			return;
		}
		
		CardView->SetIsInteractionEnabled(false);
	}
}

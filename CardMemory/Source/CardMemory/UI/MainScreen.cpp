// // Nathan Barker Card Memory Game Personal Training Project. 

#include "MainScreen.h"
#include "CardMemory/UI/CardMemoryHUD.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "GameplayTagContainer.h"

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
	if(!IsValid(WidgetViewModel))
	{
		return;
	}
	// refresh data
}

void UMainScreen::PopulateDeck(FGameplayTag InChannel, const FCardsMessage& InMessage)
{
}

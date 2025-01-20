// // Nathan Barker Card Memory Game Personal Training Project. 


#include "MainScreen.h"
#include "CardMemory/Gameplay/CardMemoryGameModeBase.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "GameplayTagContainer.h"


void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageSubsystem.RegisterListener(UIMessagePopulateCards, this, &UMainScreen::PopulateDeck);
	
	WidgetViewModel = GetVM<UCardLevelViewModel>();
	SetViewModel(WidgetViewModel);

	MessageSubsystem.BroadcastMessage(UIMessageControllerReady, nullptr);
}

void UMainScreen::UpdateWidget()
{
	if(!IsValid(WidgetViewModel))
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::Printf(TEXT("Worked")));
	// set text, image here
}

void UMainScreen::PopulateDeck(FGameplayTag InChannel, const FCardsMessage& InMessage)
{
}

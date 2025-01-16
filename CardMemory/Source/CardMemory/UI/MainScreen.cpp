// // Nathan Barker Card Memory Game Personal Training Project. 


#include "MainScreen.h"
#include "CardMemory/Gameplay/CardMemoryGameModeBase.h"
#include "GameplayTagContainer.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageSubsystem.RegisterListener(UIMessagePopulateCards, this, &UMainScreen::PopulateDeck);
}

void UMainScreen::PopulateDeck(FGameplayTag InChannel, const FCardsMessage& InMessage)
{
}

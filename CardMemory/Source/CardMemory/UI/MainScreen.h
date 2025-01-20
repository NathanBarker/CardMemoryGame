// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemoryWidget.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "CardMemory/Payloads/CardsPayload.h"
#include "MainScreen.generated.h"

class UGridPanel;
class UCardLevelViewModel;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UMainScreen : public UCardMemoryWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void UpdateWidget() override;
	void PopulateDeck(FGameplayTag InChannel, const FCardsMessage& InMessage);

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UGridPanel> CardDeck = nullptr;
	
	UPROPERTY(Transient)
	TObjectPtr<UCardLevelViewModel> WidgetViewModel = nullptr;
};

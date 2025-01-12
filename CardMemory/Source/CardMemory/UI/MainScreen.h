// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CardMemory/Payloads/CardsPayload.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "MainScreen.generated.h"

class UGridPanel;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UMainScreen : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	void PopulateDeck(FGameplayTag InChannel, const FCardsMessage& InMessage);

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UGridPanel> CardDeck = nullptr;
};

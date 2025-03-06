// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemoryWidget.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "MainScreen.generated.h"

class UUniformGridPanel;
class UCardMemoryButtonBase;
class UCardView;
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
	void FlipCardsBack(FGameplayTag InChannel, const FGuid& InMessage);
	void DisableCards(FGameplayTag InChannel, const FGuid& InMessage);

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUniformGridPanel> CardDeck = nullptr;
	
	UPROPERTY(Transient)
	TObjectPtr<UCardLevelViewModel> WidgetViewModel = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCardMemoryButtonBase> CardTemplate = nullptr;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

	UPROPERTY(EditDefaultsOnly)
	int32 ColumnMaxCount = 0;
};

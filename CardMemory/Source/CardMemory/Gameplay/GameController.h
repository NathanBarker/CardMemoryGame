// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemory/ViewModels/CardViewModel.h"
#include "NativeGameplayTags.h"
#include "CardMemory/ViewModels/LevelVMs/CardLevelViewModel.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "GameController.generated.h"

CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_MessageFlipCardsBack);
CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_DisableCards);

class UGameplayMessageSubsystem;
class UCardLevelViewModel;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API AGameController : public APlayerController
{
	GENERATED_BODY()

public:
	TArray<UCardViewModel*> CreateDeck(const int32 Level);
	void AssignLevelViewModel(UCardLevelViewModel* CardLevelViewModel);

private:
	void CheckFlippedCards(FGameplayTag InChannel, const FGuid& InMessage);
	void BroadcastCardResult();
	
	int32 Level0CardAmount = 6;

	int32 FirstSelectedCardGUID = -1;

	UPROPERTY()
	UCardLevelViewModel* LevelViewModel = nullptr;
	
	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

	FTimerHandle DelayTimerHandle;
	FGuid OutGoingMessage;
};

// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"

#include "CardMemory/ViewModels/CardViewModel.h"

#include "GameFramework/PlayerController.h"
#include "GameFramework/GameplayMessageSubsystem.h"

#include "NativeGameplayTags.h"
#include "Types/MVVMViewModelContext.h"

#include "GameController.generated.h"

CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_MessageFlipCardsBack);
CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_DisableCards);

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
	void RandomiseCardData(UCardViewModel& CardViewModel, UCardViewModel& PairedCardViewModel);

	static FMVVMViewModelContext CreateCardVMContext();

	UPROPERTY(EditAnywhere)
	int32 Level0CardAmount = 0;

	int32 FirstSelectedCardGUID = -1;

	TArray<int32> CrossPatterns = {};
	TArray<int32> TrianglePatterns = {};
	TArray<int32> SquarePatterns = {};
	TArray<int32> CirclePatterns = {};

	TArray<TArray<int32>> AllUsedPatterns = {};

	bool ValidCardEntry = true;

	UPROPERTY()
	UCardLevelViewModel* LevelViewModel = nullptr;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

	FTimerHandle DelayTimerHandle;
	FGuid OutGoingMessage;
};

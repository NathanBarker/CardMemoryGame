// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NativeGameplayTags.h"
#include "CardMemory/ViewModels/CardViewModel.h"
#include "GameController.generated.h"

CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UIMessagePopulateCards);

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

protected:
	virtual void BeginPlay() override;

private:
	int32 Level0CardAmount = 6;
};

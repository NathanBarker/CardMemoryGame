// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NativeGameplayTags.h"
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

protected:
	virtual void BeginPlay() override;
};

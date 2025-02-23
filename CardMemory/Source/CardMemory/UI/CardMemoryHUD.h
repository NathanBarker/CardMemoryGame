// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NativeGameplayTags.h"
#include "CardMemoryHUD.generated.h"

CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UIMessagePopulateCards);

class UGameplayMessageSubsystem;
class UCardLevelViewModel;
class AGameController;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API ACardMemoryHUD : public AHUD
{
	GENERATED_BODY()

	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

	UPROPERTY()
	TObjectPtr<UCardLevelViewModel> CardLevelViewModel = nullptr;

	UPROPERTY()
	TObjectPtr<AGameController> GameController = nullptr;
};

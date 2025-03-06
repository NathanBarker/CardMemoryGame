// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemoryButtonBase.h"
#include "CommonButtonBase.h"
#include "NativeGameplayTags.h"
#include "CardMemory/GameData/CardModel.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "CardView.generated.h"

CARDMEMORY_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_MessageCardSelected);

class UCommonLazyImage;
class UCardPatternView;
class UCardViewModel;
class UWidgetSwitcher;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardView : public UCardMemoryButtonBase
{
	GENERATED_BODY()

public:
	void FlipCard();
	void HideCard();
	bool IsHidden = true;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnSelected(bool bBroadcast) override;
	virtual void NativeOnDeselected(bool bBroadcast) override;
	virtual void NativeOnClicked() override;
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;
	virtual void UpdateWidget() override;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCardPatternView> PatternContainer = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher = nullptr;

	UPROPERTY()
	TObjectPtr<UCardViewModel> CardWidgetViewModel;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<TSoftObjectPtr<UTexture2D>> PSIcons;
	
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> RevealCard;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;
	
	void SetCardIcon(const EType& Type);
	void SetCardPattern(const int32& PatternType);
	void SetCardRevealedState(bool IsRevealed);
	
	bool IsCardRevealed = false;
};

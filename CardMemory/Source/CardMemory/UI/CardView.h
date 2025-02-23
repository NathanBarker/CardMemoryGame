// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemoryButtonBase.h"
#include "CommonButtonBase.h"
#include "CardMemory/GameData/CardModel.h"
#include "CardView.generated.h"

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

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnSelected(bool bBroadcast) override;
	virtual void NativeOnDeselected(bool bBroadcast) override;
	virtual void NativeOnClicked() override;
	virtual void NativeOnEnabled() override;
	virtual void NativeOnDisabled() override;
	virtual void NativeOnHovered() override;
	virtual void NativeOnUnhovered() override;
	virtual void HandleFocusReceived() override;
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
	
	void SetCardIcon(const EType& Type);
	void SetCardPattern(const int32& PatternType);
	void SetCardRevealedState(bool IsRevealed);
	void FlipCard();

	bool IsHidden = true;
	bool IsCardRevealed = false;
};

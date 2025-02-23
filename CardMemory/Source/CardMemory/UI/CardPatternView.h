// Nathan Barker Card Memory Game Personal Training Project. 

#pragma once


#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CardPatternView.generated.h"

class UWidgetSwitcher;
class UCommonLazyImage;
class UOverlay;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardPatternView : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	void SetIconForPattern(const TSoftObjectPtr<UTexture2D>& PSIcon);
	void ShowPattern(const int32& PatternIndex);

protected:
	virtual void NativeConstruct() override;

private:
	TArray<TObjectPtr<UCommonLazyImage>> AllCardIcons = {};
	TArray<TObjectPtr<UOverlay>> PatternOverlays = {};

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWidgetSwitcher> PatternWidgetSwitcher = nullptr;
};

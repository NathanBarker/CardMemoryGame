// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CommonUserWidget.h"
#include "CardMemory/GameData/CardModel.h"
#include "CardView.generated.h"

class UCommonLazyImage;
class UCardPatternView;
class UCardViewModel;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardView : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnSelected(bool bBroadcast) override;
	virtual void NativeOnDeselected(bool bBroadcast) override;
	virtual void NativeOnEnabled() override;
	virtual void NativeOnDisabled() override;
	virtual void NativeOnHovered() override;
	virtual void NativeOnUnhovered() override;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> PSIcon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCardPatternView> PatternContainer = nullptr;

	UPROPERTY()
	TObjectPtr<UCardViewModel> CardVM;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<TSoftObjectPtr<UTexture2D>> PSIcons;
	

	void SetCardData(const TObjectPtr<UCardViewModel>& CardViewModel);
	void SetPSIcon(EType Type);
};

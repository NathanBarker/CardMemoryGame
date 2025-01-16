// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
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
class CARDMEMORY_API UCardView : public UCommonUserWidget
{
	GENERATED_BODY()

public:

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> PSIcon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCardPatternView> PatternContainer = nullptr;

	UPROPERTY()
	TObjectPtr<UCardViewModel> CardVM;

	void SetCardData(const TObjectPtr<UCardViewModel>& CardViewModel);
	void SetPSIcon(EType Type);
};

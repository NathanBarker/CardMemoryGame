// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CardView.generated.h"

class UCommonLazyImage;
class UCardPatternView;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardView : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> PSICon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCardPatternView> PatternContainer = nullptr;
};

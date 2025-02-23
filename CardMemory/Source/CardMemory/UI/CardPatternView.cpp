// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardPatternView.h"

#include "CommonLazyImage.h"
#include "Blueprint/WidgetTree.h"
#include "Components/WidgetSwitcher.h"

void UCardPatternView::SetIconForPattern(const TSoftObjectPtr<UTexture2D>& PSIcon)
{
	for (UCommonLazyImage* CardIcon : AllCardIcons)
	{
		CardIcon->SetBrushFromLazyTexture(PSIcon);
	}
}

void UCardPatternView::ShowPattern(const int32& PatternIndex)
{
	PatternWidgetSwitcher->SetActiveWidgetIndex(PatternIndex);
}

void UCardPatternView::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UWidget*> Children;
	WidgetTree->GetAllWidgets(Children);

	for (UWidget* Child : Children)
	{
		if (UCommonLazyImage* LazyImage = Cast<UCommonLazyImage>(Child))
		{
			AllCardIcons.Emplace(LazyImage);
		}
	}
}

// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardPatternView.h"

#include "CommonLazyImage.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Overlay.h"

void UCardPatternView::SetIconForPattern(const TSoftObjectPtr<UTexture2D>& PSIcon)
{
	for (UCommonLazyImage* CardIcon : AllCardIcons)
	{
		CardIcon->SetBrushFromLazyTexture(PSIcon);
	}
}

void UCardPatternView::ShowPattern(const int32& PatternIndex)
{
	for (UOverlay* PatternOverlay : PatternOverlays)
	{
		PatternOverlay->SetVisibility(ESlateVisibility::Hidden);
	}
	PatternOverlays[PatternIndex]->SetVisibility(ESlateVisibility::Visible);
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

	PatternOverlays.Emplace(Pattern1);
	PatternOverlays.Emplace(Pattern2);
	PatternOverlays.Emplace(Pattern3);
	PatternOverlays.Emplace(Pattern4);
}

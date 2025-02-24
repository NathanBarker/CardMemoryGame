// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardView.h"

#include "CardPatternView.h"
#include "CommonLazyImage.h"
#include "CardMemory/ViewModels/CardViewModel.h"
#include "Components/WidgetSwitcher.h"

void UCardView::NativeConstruct()
{
	Super::NativeConstruct();

	if (!IsValid(WidgetViewModel))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the Card View Model while constructing the widget"));
	}
	CardWidgetViewModel = Cast<UCardViewModel>(WidgetViewModel);
	UpdateWidget();
	WidgetSwitcher->SetActiveWidgetIndex(IsHidden);
	UnbindTriggeringInputActionToClick();
}

void UCardView::NativeOnSelected(bool bBroadcast)
{
	Super::NativeOnSelected(bBroadcast);
}

void UCardView::NativeOnDeselected(bool bBroadcast)
{
	Super::NativeOnDeselected(bBroadcast);
}

void UCardView::NativeOnClicked()
{
	Super::NativeOnClicked();
	FlipCard();
}

void UCardView::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnRemovedFromFocusPath(InFocusEvent);
	UnbindTriggeringInputActionToClick();
	SetSelectedInternal(false);
}

void UCardView::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnAddedToFocusPath(InFocusEvent);
	BindTriggeringInputActionToClick();
	SetSelectedInternal(true);
}

void UCardView::UpdateWidget()
{
	SetCardIcon(CardWidgetViewModel->GetType());
	SetCardPattern(CardWidgetViewModel->GetPatternType());
}

void UCardView::SetCardIcon(const EType& Type)
{
	TSoftObjectPtr<UTexture2D> NewIcon = PSIcons[static_cast<int32>(Type)];
	PatternContainer->SetIconForPattern(NewIcon);
}

void UCardView::SetCardPattern(const int32& PatternType)
{
	PatternContainer->ShowPattern(PatternType);
}

void UCardView::SetCardRevealedState(bool IsRevealed)
{
	IsCardRevealed = IsRevealed;
	WidgetSwitcher->SetActiveWidgetIndex(IsRevealed);
	WidgetSwitcher->SetRenderOpacity(0.75f);
}

void UCardView::FlipCard()
{
	if (IsCardRevealed) return;
	IsHidden = !IsHidden;
	WidgetSwitcher->SetActiveWidgetIndex(IsHidden);
}

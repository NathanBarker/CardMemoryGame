// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardView.h"

#include "CardPatternView.h"
#include "CommonLazyImage.h"
#include "CardMemory/ViewModels/CardViewModel.h"
#include "Components/WidgetSwitcher.h"

UE_DEFINE_GAMEPLAY_TAG(UI_MessageCardSelected, "UI_MessageCardSelected");

void UCardView::NativeConstruct()
{
	Super::NativeConstruct();

	if (!IsValid(WidgetViewModel))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get the Card View Model while constructing the widget"));
	}
	
	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	check(MessageSubsystem);

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
	if (IsCardRevealed || !IsHidden) return;
	Super::NativeOnClicked();

	FlipCard();
	const int32 CardIndex = CardWidgetViewModel->GetCardGUID();
	FGuid OutgoingMessage(CardIndex, 0, 0, 0);
	MessageSubsystem->BroadcastMessage(UI_MessageCardSelected, OutgoingMessage);
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

	if(CardWidgetViewModel->GetIsRevealed())
	{
		SetCardRevealedState(CardWidgetViewModel->GetIsRevealed());
	}
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
	WidgetSwitcher->SetActiveWidgetIndex(0);
	WidgetSwitcher->SetRenderOpacity(0.75f);
}

void UCardView::FlipCard()
{
	PlayAnimation(RevealCard, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f);
	IsHidden = !IsHidden;
	WidgetSwitcher->SetActiveWidgetIndex(IsHidden);
}

void UCardView::HideCard()
{
	if(IsCardRevealed) return;
	PlayAnimation(RevealCard, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f);
	IsHidden = true;
	WidgetSwitcher->SetActiveWidgetIndex(IsHidden);
}

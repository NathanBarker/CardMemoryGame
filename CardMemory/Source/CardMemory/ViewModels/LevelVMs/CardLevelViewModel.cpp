// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardLevelViewModel.h"

UCardLevelViewModel::UCardLevelViewModel()
{
	ConstructFieldsDelegates();
}

void UCardLevelViewModel::SetCardViewModels(const TArray<UCardViewModel*>& NewCardViewModels)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(CardViewModels, NewCardViewModels))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(CardViewModels);
	}
}

TArray<UCardViewModel*> UCardLevelViewModel::GetCardViewModels() const
{
	return CardViewModels;
}

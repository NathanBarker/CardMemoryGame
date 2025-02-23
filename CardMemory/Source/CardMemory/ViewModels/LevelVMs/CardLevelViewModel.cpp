// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardLevelViewModel.h"

UCardLevelViewModel::UCardLevelViewModel()
{
	ConstructFieldsDelegates();
}

void UCardLevelViewModel::SetCardViewModels(const TArray<UCardViewModel*>& NewCardViewModels)
{
	UE_MVVM_SET_PROPERTY_VALUE(CardViewModels, NewCardViewModels);
}

TArray<UCardViewModel*> UCardLevelViewModel::GetCardViewModels() const
{
	return CardViewModels;
}

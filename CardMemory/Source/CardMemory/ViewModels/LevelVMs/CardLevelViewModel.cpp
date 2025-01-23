// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardLevelViewModel.h"

UCardLevelViewModel::UCardLevelViewModel()
{
	ConstructFieldsDelegates();
}

void UCardLevelViewModel::SetCardViewModelsNewName(const TArray<UCardViewModel*>& NewCardViewModelsNewName)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(CardViewModelsNewName, NewCardViewModelsNewName))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(CardViewModelsNewName);
	}
}

TArray<UCardViewModel*> UCardLevelViewModel::GetCardViewModelsNewName() const
{
	return CardViewModelsNewName;
}

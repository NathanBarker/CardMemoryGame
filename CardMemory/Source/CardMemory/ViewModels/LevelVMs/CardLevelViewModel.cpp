// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardLevelViewModel.h"

UCardLevelViewModel::UCardLevelViewModel()
{
	TArray<FName> DataObjectNames = {};
	DataObjectNames.Emplace(GET_MEMBER_NAME_CHECKED(UCardLevelViewModel,CardViewModelsNewName));
	ConstructFieldsDelegates(DataObjectNames,this);
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

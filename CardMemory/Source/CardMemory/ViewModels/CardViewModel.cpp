// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardViewModel.h"

UCardViewModel::UCardViewModel()
{
	ConstructFieldsDelegates();
}

void UCardViewModel::SetType(const EType NewType)
{
	UE_MVVM_SET_PROPERTY_VALUE(Type, NewType);
}

void UCardViewModel::SetPatternType(const int32& NewPatternType)
{
	UE_MVVM_SET_PROPERTY_VALUE(PatternType, NewPatternType);
}

void UCardViewModel::SetIsRevealed(const bool NewIsRevealed)
{
	UE_MVVM_SET_PROPERTY_VALUE(IsRevealed, NewIsRevealed);
}

void UCardViewModel::SetCardGUID(const int32 NewGUID)
{
	UE_MVVM_SET_PROPERTY_VALUE(CardGUID, NewGUID);
}

bool UCardViewModel::GetIsRevealed() const
{
	return IsRevealed;
}

int32 UCardViewModel::GetCardGUID() const
{
	return CardGUID;
}

int32 UCardViewModel::GetPatternType() const
{
	return PatternType;
}

EType UCardViewModel::GetType() const
{
	return Type;
}

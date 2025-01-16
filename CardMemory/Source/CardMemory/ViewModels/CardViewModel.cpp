// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardViewModel.h"

UCardViewModel::UCardViewModel()
{
	ConstructFieldsDelegates();
}

void UCardViewModel::SetType(const EType NewType)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(Type, NewType))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(Type);
	}
}

void UCardViewModel::SetPatternType(const int32& NewPatternType)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(PatternType, NewPatternType))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(PatternType);
	}
}

void UCardViewModel::SetIsRevealed(const bool NewIsRevealed)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(IsRevealed, NewIsRevealed))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(IsRevealed);
	}
}

bool UCardViewModel::GetIsRevealed() const
{
	return IsRevealed;
}

int32 UCardViewModel::GetPatternType() const
{
	return PatternType;
}

EType UCardViewModel::GetType() const
{
	return Type;
}

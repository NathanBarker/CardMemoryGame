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

void UCardViewModel::SetCardIndex(const int32 NewIndex)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(CardIndex, NewIndex))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(CardIndex);
	}
}

void UCardViewModel::SetPairIndex(const int32 NewPairIndex)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(PairIndex, NewPairIndex))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(PairIndex);
	}
}

bool UCardViewModel::GetIsRevealed() const
{
	return IsRevealed;
}

int32 UCardViewModel::GetCardIndex() const
{
	return CardIndex;
}

int32 UCardViewModel::GetPairIndex() const
{
	return PairIndex;
}

int32 UCardViewModel::GetPatternType() const
{
	return PatternType;
}

EType UCardViewModel::GetType() const
{
	return Type;
}

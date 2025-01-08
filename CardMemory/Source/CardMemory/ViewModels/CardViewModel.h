// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "CardMemory/GameData/CardModel.h"
#include "CardViewModel.generated.h"

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(FieldNotify, Setter, Getter)
	EType Type = EType::Cross;

	UPROPERTY(FieldNotify, Setter, Getter)
	int32 PatternType = -1;

	UPROPERTY(FieldNotify, Setter, Getter)
	bool bIsRevealed = false;

public:
	void SetType(const EType NewType)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(Type, NewType))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(Type);
		}
	}
	
	void SetPatternType(const int32 NewPatternType)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(PatternType, NewPatternType))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(PatternType);
		}
	}

	void SetbIsRevealed(bool NewbIsRevealed)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(bIsRevealed, NewbIsRevealed))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(bIsRevealed);
		}
	}

	bool GetbIsRevealed() const
	{
		return bIsRevealed;
	}

	int32 GetPatternType() const
	{
		return PatternType;
	}

	EType GetType() const
	{
		return Type;
	}
};

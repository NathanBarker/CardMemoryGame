// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemoryMVVMViewModelBase.h"
#include "CardMemory/GameData/CardModel.h"
#include "CardViewModel.generated.h"

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardViewModel : public UCardMemoryMVVMViewModelBase
{
	GENERATED_BODY()
	
public:
	UCardViewModel();

	void SetType(const EType NewType);
	void SetPatternType(const int32& NewPatternType);
	void SetIsRevealed(const bool NewIsRevealed);
	void SetCardIndex(const int32 NewIndex);
	void SetPairIndex(const int32 NewPairIndex);
	
	EType GetType() const;
	int32 GetPatternType() const;
	bool GetIsRevealed() const;
	int32 GetCardIndex() const;
	int32 GetPairIndex() const;
	

private:
	UPROPERTY(FieldNotify, Setter, Getter)
	EType Type = EType::Cross;

	UPROPERTY(FieldNotify, Setter, Getter)
	int32 PatternType = -1;

	UPROPERTY(FieldNotify, Setter, Getter)
	bool IsRevealed = false;
	
	UPROPERTY(FieldNotify, Setter, Getter)
	int32 CardIndex = -1;
	
	UPROPERTY(FieldNotify, Setter, Getter)
	int32 PairIndex = -1;
};

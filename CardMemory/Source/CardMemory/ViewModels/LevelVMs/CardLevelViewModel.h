// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CardMemory/ViewModels/CardMemoryMVVMViewModelBase.h"
#include "CardMemory/ViewModels/CardViewModel.h"
#include "CardLevelViewModel.generated.h"

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardLevelViewModel : public UCardMemoryMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UCardLevelViewModel();

	void SetCardViewModels(const TArray<UCardViewModel*>& NewCardViewModels);
	TArray<UCardViewModel*> GetCardViewModels() const;

private:

	UPROPERTY(FieldNotify, Getter, Setter)
	TArray<UCardViewModel*> CardViewModels = {};
};

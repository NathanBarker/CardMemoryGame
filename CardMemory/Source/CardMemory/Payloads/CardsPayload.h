#pragma once
#include "CardMemory/ViewModels/CardViewModel.h"

USTRUCT()
struct FCardsMessage
{
	GENERATED_BODY()

	TArray<UCardViewModel> CardViewModels = {};
};

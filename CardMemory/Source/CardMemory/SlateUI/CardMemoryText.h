// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class CARDMEMORY_API SCardMemoryText : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCardMemoryText)
		{
		}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	FText GetTime() const;
};

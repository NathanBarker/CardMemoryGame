// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class CARDMEMORY_API SCardMemoryImage : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCardMemoryImage)
		{
		}

		SLATE_ARGUMENT(FSlateBrush*, Brush)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	FSlateBrush* Brush;
};

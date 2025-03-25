// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardMemoryImage.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SCardMemoryImage::Construct(const FArguments& InArgs)
{
	ChildSlot
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(InArgs._Brush)
			]
		];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

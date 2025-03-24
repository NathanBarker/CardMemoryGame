// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardMemoryText.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SCardMemoryText::Construct(const FArguments& InArgs)
{
	ChildSlot
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SBorder)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
			[
				SNew(STextBlock)
				.Text(this, &SCardMemoryText::GetTime)
			]
		];
}

FText SCardMemoryText::GetTime() const
{
	FDateTime CurrentTime = FDateTime::Now();
	return FText::FromString(CurrentTime.ToString(TEXT("%H:%M:%S")));
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CardMemoryButtonBase.generated.h"

class UCardMemoryMVVMViewModelBase;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardMemoryButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	
	void SetViewModel(UCardMemoryMVVMViewModelBase* ViewModelInstance);
	virtual void UpdateWidget(){};

protected:

	UPROPERTY()
	TObjectPtr<UCardMemoryMVVMViewModelBase> WidgetViewModel = nullptr;
};

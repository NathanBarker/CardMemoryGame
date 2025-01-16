// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "CardMemoryMVVMViewModelBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDataUpdate);

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardMemoryMVVMViewModelBase : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UCardMemoryMVVMViewModelBase() = default;
	FOnDataUpdate Data;

protected:
	void ConstructFieldsDelegates();
	void OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId);
	void BroadcastChange();
};

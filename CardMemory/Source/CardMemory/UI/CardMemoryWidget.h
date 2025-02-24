// // Nathan Barker Card Memory Game Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonUserWidget.h"
#include "MVVMGameSubsystem.h"
#include "CardMemoryWidget.generated.h"

class UCardMemoryMVVMViewModelBase;

/**
 * 
 */
UCLASS()
class CARDMEMORY_API UCardMemoryWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	template <typename T = UMVVMViewModelBase>
	T* GetVM()
	{
		const UGameInstance* GameInstance = GetWorld()->GetGameInstance();
		check(GameInstance);

		UMVVMGameSubsystem* ViewModelGameSubsystem = GameInstance->GetSubsystem<UMVVMGameSubsystem>();
		check(ViewModelGameSubsystem);

		UMVVMViewModelBase* ViewModelInstance = ViewModelGameSubsystem->GetViewModelCollection()->FindFirstViewModelInstanceOfType(
			T::StaticClass());

		if (IsValid(ViewModelInstance))
		{
			T* CustomViewModel = Cast<T>(ViewModelInstance);
			return CustomViewModel;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get VM instance"));
			return nullptr;
		}
	}

	void SetViewModel(UCardMemoryMVVMViewModelBase* ViewModelInstance);
	virtual void UpdateWidget(){};
};

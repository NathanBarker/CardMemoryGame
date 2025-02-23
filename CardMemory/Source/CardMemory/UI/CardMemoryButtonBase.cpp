// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardMemoryButtonBase.h"
#include "CardMemory/ViewModels/CardMemoryMVVMViewModelBase.h"

void UCardMemoryButtonBase::SetViewModel(UCardMemoryMVVMViewModelBase* ViewModelInstance)
{
	if(!IsValid(ViewModelInstance))
	{
		return;
	}
	WidgetViewModel = ViewModelInstance;
	ViewModelInstance->ViewModelData.AddUObject(this, &UCardMemoryButtonBase::UpdateWidget);
}

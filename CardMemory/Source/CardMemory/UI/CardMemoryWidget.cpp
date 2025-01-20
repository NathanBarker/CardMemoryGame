// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardMemoryWidget.h"
#include "CardMemory/ViewModels/CardMemoryMVVMViewModelBase.h"

void UCardMemoryWidget::SetViewModel(UCardMemoryMVVMViewModelBase* ViewModelInstance)
{
	if(!IsValid(ViewModelInstance))
	{
		return;
	}
	ViewModelInstance->ViewModelData.AddUObject(this, &UCardMemoryWidget::UpdateWidget);
}

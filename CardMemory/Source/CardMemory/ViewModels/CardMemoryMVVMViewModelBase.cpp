// // Nathan Barker Card Memory Game Personal Training Project. 


#include "CardMemoryMVVMViewModelBase.h"

void UCardMemoryMVVMViewModelBase::ConstructFieldsDelegates()
{
	GetFieldNotificationDescriptor().ForEachField(StaticClass(),
	                                              [this](const UE::FieldNotification::FFieldId FieldID) -> bool
	                                              {
		                                              if (FieldID.IsValid())
		                                              {
			                                              FFieldValueChangedDelegate Delegate;
			                                              AddFieldValueChangedDelegate(FieldID, Delegate);
			                                              Delegate.BindUObject(
				                                              this, &UCardMemoryMVVMViewModelBase::OnFieldChanged);
			                                              return true;
		                                              }
		                                              return false;
	                                              });
}

void UCardMemoryMVVMViewModelBase::OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId)
{
	BroadcastChange();
}

void UCardMemoryMVVMViewModelBase::BroadcastChange()
{
	ViewModelData.Broadcast();
}

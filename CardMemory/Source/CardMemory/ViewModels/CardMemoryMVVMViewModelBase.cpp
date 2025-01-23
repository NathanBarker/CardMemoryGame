// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardMemoryMVVMViewModelBase.h"

#include "IDetailTreeNode.h"

void UCardMemoryMVVMViewModelBase::ConstructFieldsDelegates()
{
	GetFieldNotificationDescriptor().ForEachField(StaticClass(),
	                                              [this](const UE::FieldNotification::FFieldId FieldID) -> bool
	                                              {
		                                              if (FieldID.IsValid())
		                                              {
			                                              FFieldValueChangedDelegate Delegate;
			                                              Delegate.BindUObject(this, &ThisClass::OnFieldChanged);
			                                              AddFieldValueChangedDelegate(FieldID, Delegate);
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

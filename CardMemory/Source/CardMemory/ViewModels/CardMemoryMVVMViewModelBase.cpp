// // Nathan Barker Card Memory Game Personal Training Project. 

#include "CardMemoryMVVMViewModelBase.h"

#include "IDetailTreeNode.h"

void UCardMemoryMVVMViewModelBase::ConstructFieldsDelegates(const TArray<FName>& ObjectNames,
                                                            UCardMemoryMVVMViewModelBase* VMClass)
{
 	if (!IsValid(VMClass))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to gacst the ViewModel context while constructing field delegates"));
		return;
	}

	for (const FName ObjectName : ObjectNames)
	{
		const UE::FieldNotification::FFieldId FieldID = VMClass->GetFieldNotificationDescriptor().GetField(
			VMClass->GetClass(), ObjectName);
		FFieldValueChangedDelegate Delegate;
		AddFieldValueChangedDelegate(FieldID, Delegate);
		Delegate.BindUObject(this, &UCardMemoryMVVMViewModelBase::OnFieldChanged);
	}
}

void UCardMemoryMVVMViewModelBase::OnFieldChanged(UObject* Object, UE::FieldNotification::FFieldId FieldId)
{
	BroadcastChange();
}

void UCardMemoryMVVMViewModelBase::BroadcastChange()
{
	ViewModelData.Broadcast();
}

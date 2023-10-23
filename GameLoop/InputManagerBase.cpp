#include<InputManagerBase.h>

InputManagerBase* InputManagerBase::event_handling_instance = nullptr;

void InputManagerBase::setEventHandling()
{
	event_handling_instance = this;
}

#include "EventMemberFunction.hpp"

namespace sn
{
	template<typename T, typename EventType>
	EventMemberFunction<T, EventType>::EventMemberFunction(T* p_Instance, EventMemberFunction::EventFunctionPtr p_Function)
	{
		m_Instance = p_Instance;
		m_Function = p_Function;
	}

	template<typename T, typename EventType>
	void EventMemberFunction<T, EventType>::Call(Event* p_Event)
	{
		(m_Instance->*m_Function)(static_cast<EventType*>(p_Event));
	}
}
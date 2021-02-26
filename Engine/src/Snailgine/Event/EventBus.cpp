#include "EventBus.hpp"

namespace sn
{
	EventBus::EventBus()
	{
		m_Subscribers = {};
	}

	EventBus& EventBus::Instance()
	{
		static EventBus s_Instance;
		return s_Instance;
	}

	template<typename T, typename EventType>
	void EventBus::Subscribe(T* p_Instance, void (T::*p_Function)(EventType*))
	{
		EventHandleList* handlers = m_Subscribers[typeid(EventType)];

		//First time initialization
		if (handlers == nullptr)
		{
			handlers = new EventHandleList();
			m_Subscribers[typeid(EventType)] = handlers;
		}

		handlers->push_back(new EventMemberFunction<T, EventType>(p_Instance, p_Function));
	}

	template<typename EventType>
	void EventBus::Publish(EventType * p_Event)
	{
		EventHandleList* f_Handlers = m_Subscribers[typeid(EventType)];

		if (f_Handlers == nullptr)
			return;

		for (auto& f_Handler : *f_Handlers)
			if (f_Handler != nullptr)
				f_Handler->Execute(p_Event);
	}
}

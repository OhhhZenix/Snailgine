#pragma once

#include "Snailgine/Event/EventBaseFunction.hpp"

namespace sn
{
	template<typename T, typename EventType>
	class EventMemberFunction : public EventBaseFunction
	{
	 private:
		using EventFunctionPtr = void (T::*)(EventType&);

		T* m_Instance;
		EventFunctionPtr m_Function;

	 public:
		EventMemberFunction(T* p_Instance, EventMemberFunction::EventFunctionPtr p_Function)
		{
			m_Instance = p_Instance;
			m_Function = p_Function;
		}


		void Call(Event& p_Event) override
		{
			(m_Instance->*m_Function)(static_cast<EventType&>(p_Event));
		}
	};
}
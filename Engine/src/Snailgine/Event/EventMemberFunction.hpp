#pragma once

#include "Snailgine/Event/EventBaseFunction.hpp"

namespace sn
{
	template<typename T, typename EventType>
	class EventMemberFunction : public EventBaseFunction
	{
	 private:
		using EventFunctionPtr = void (T::*)(EventType*);

		T* m_Instance;
		EventFunctionPtr m_Function;

	 public:
		EventMemberFunction(T* p_Instance, EventFunctionPtr p_Function);

		void Call(Event* p_Event) override;
	};
}
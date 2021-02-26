#pragma once

#include "Snailgine/Core/Base.hpp"
#include "Snailgine/Event/EventMemberFunction.hpp"

namespace sn
{
	class EventBus
	{
	 private:
		using EventHandleList = std::list<EventBaseFunction*>;

		std::map<std::type_index, EventHandleList*> m_Subscribers;

	 private:
		EventBus();

	 public:
		static EventBus& Instance();

		template<typename T, typename EventType>
		void Subscribe(T* p_Instance, void (T::*p_Function)(EventType*));

		template<typename EventType>
		void Publish(EventType * p_Event);

	 public:
		// Copy construct
		EventBus(EventBus const&) = delete;

		// Move construct
		EventBus(EventBus&&) = delete;

		// Copy assign
		EventBus& operator=(EventBus const&) = delete;

		// Move assign
		EventBus& operator=(EventBus&&) = delete;
	};
}
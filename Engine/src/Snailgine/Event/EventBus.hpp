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

		~EventBus();

	 public:
		static EventBus& Instance();

		template<typename T, typename EventType>
		void Subscribe(T* p_Instance, void (T::*p_Function)(EventType*))
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
		void Publish(EventType * p_Event)
		{
			EventHandleList* f_Handlers = m_Subscribers[typeid(EventType)];

			if (f_Handlers == nullptr)
				return;

			for (auto& f_Handler : *f_Handlers)
				if (f_Handler != nullptr)
					f_Handler->Execute(p_Event);
		}

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
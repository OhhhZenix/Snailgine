#include "EventBus.hpp"

namespace sn
{
	EventBus::EventBus()
	{
		m_Subscribers = {};
	}

	EventBus::~EventBus()
	{
		if (!m_Subscribers.empty())
		{
			for (auto[f_Key, f_Value] :m_Subscribers)
			{
				if (f_Value.empty())
					continue;
				for (EventBaseFunction* f_Item : f_Value) {
					delete f_Item;
				}
				f_Value.clear();
			}
			m_Subscribers.clear();
		}
	}

	EventBus& EventBus::Instance()
	{
		static EventBus s_Instance;
		return s_Instance;
	}
}

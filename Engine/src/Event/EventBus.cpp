#include "Snailgine/Event/EventBus.hpp"

#include <Snailgine/Core/Log.hpp>

namespace sn {

static bool s_event_bus_initialize = false;

void EventBus::init() {
	if (s_event_bus_initialize) {
		SN_LOG_ASSERT(false, "EventBus already initialized!")
		return;
	}
	s_event_bus_initialize = true;
}

void EventBus::shutdown() {
	if (!s_event_bus_initialize) {
		SN_LOG_ASSERT(false, "EventBus already uninitialized!")
		return;
	}
	if (!s_subscribers.empty()) {
		for (auto [l_key, l_value] : s_subscribers) {
			if (l_value.empty()) {
				continue;
			}
			for (IEventCallback* l_item : l_value) {
				delete l_item;
			}
			l_value.clear();
		}
		s_subscribers.clear();
	}
	s_event_bus_initialize = false;
}

std::unordered_map<std::type_index, EventBus::FunctionList> EventBus::s_subscribers = {};

} // namespace sn
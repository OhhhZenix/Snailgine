#pragma once

#include <Snailgine/Event/Event.hpp>

namespace sn {

class WindowCloseEvent : public Event {
public:
	EventType get_event_type() const override;

	EventCategory get_event_categories() const override;
};

} // namespace sn
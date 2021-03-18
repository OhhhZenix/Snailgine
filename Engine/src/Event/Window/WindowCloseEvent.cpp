#include "Snailgine/Event/Window/WindowCloseEvent.hpp"

namespace sn {

EventType WindowCloseEvent::get_event_type() const {
	return EventType::WindowClose;
}
EventCategory WindowCloseEvent::get_event_categories() const {
	return EventCategory::Window;
}

} // namespace sn
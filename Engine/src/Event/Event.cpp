#include "Snailgine/Event/Event.hpp"

namespace sn {

EventCategory operator|(EventCategory p_left, EventCategory p_right) {
	return static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_left) | static_cast<std::underlying_type_t<EventCategory>>(p_right));
}

EventCategory operator&(EventCategory p_left, EventCategory p_right) {
	return static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_left) & static_cast<std::underlying_type_t<EventCategory>>(p_right));
}

EventCategory operator^(EventCategory p_left, EventCategory p_right) {
	return static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_left) ^ static_cast<std::underlying_type_t<EventCategory>>(p_right));
}

EventCategory& operator|=(EventCategory& p_left, EventCategory p_right) {
	p_left = static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_left) | static_cast<std::underlying_type_t<EventCategory>>(p_right));
	return p_left;
}

EventCategory& operator&=(EventCategory& p_left, EventCategory p_right) {
	p_left = static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_left) & static_cast<std::underlying_type_t<EventCategory>>(p_right));
	return p_left;
}

EventCategory& operator^=(EventCategory& p_left, EventCategory p_right) {
	p_left = static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_left) ^ static_cast<std::underlying_type_t<EventCategory>>(p_right));
	return p_left;
}

EventCategory operator~(EventCategory p_category) {
	return static_cast<EventCategory>(~static_cast<std::underlying_type_t<EventCategory>>(p_category));
}

Event::Event() {
	m_cancelled = false;
}

bool Event::is_in_category(EventCategory p_category) const {
	return static_cast<bool>(get_event_categories() & p_category);
}

bool Event::is_cancelled() const {
	return m_cancelled;
}

void Event::set_cancelled(bool p_cancelled) {
	m_cancelled = p_cancelled;
}

} // namespace sn
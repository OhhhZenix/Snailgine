#pragma once

#include <Snailgine/Core/Base.hpp>

namespace sn {

enum class EventType {
	None = 0,
	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,
	AppTick,
	AppUpdate,
	AppRender,
	KeyPressed,
	KeyReleased,
	KeyTyped,
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

enum class EventCategory {
	None = 0,
	Window = bit(0),
	App = bit(1),
	Keyboard = bit(2),
	Mouse = bit(3),
	MouseButton = bit(4),
	Input = bit(5)
};

EventCategory operator|(EventCategory p_left, EventCategory p_right);

EventCategory operator&(EventCategory p_left, EventCategory p_right);

EventCategory operator^(EventCategory p_left, EventCategory p_right);

EventCategory& operator|=(EventCategory& p_left, EventCategory p_right);

EventCategory& operator&=(EventCategory& p_left, EventCategory p_right);

EventCategory& operator^=(EventCategory& p_left, EventCategory p_right);

EventCategory operator~(EventCategory p_category);

class Event
{
private:
	bool m_cancelled;

public:
	Event();

	virtual ~Event() = default;

	virtual EventType get_event_type() const = 0;

	virtual EventCategory get_event_categories() const = 0;

	bool is_in_category(EventCategory p_category) const;

	bool is_cancelled() const;

	void set_cancelled(bool p_cancelled);
};

} // namespace sn
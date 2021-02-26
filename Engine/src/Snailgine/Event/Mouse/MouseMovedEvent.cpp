#include "MouseMovedEvent.hpp"

namespace sn
{
	MouseMovedEvent::MouseMovedEvent(float p_X, float p_Y)
	{
		m_X = p_Y;
		m_Y = p_Y;
	}

	EventType MouseMovedEvent::GetEventType() const
	{
		return EventType::MouseMoved;
	}

	EventCategory MouseMovedEvent::GetEventCategory() const
	{
		return EventCategory::Mouse | EventCategory::Input;
	}

	float MouseMovedEvent::GetX() const
	{
		return m_X;
	}

	float MouseMovedEvent::GetY() const
	{
		return m_Y;
	}
}
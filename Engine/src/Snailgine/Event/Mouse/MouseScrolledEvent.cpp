#include "MouseScrolledEvent.hpp"

namespace sn
{
	MouseScrolledEvent::MouseScrolledEvent(float p_XOffset, float p_YOffset)
	{
		m_XOffset = p_XOffset;
		m_YOffset = p_YOffset;
	}

	float MouseScrolledEvent::GetXOffset() const
	{
		return m_XOffset;
	}

	float MouseScrolledEvent::GetYOffset() const
	{
		return m_YOffset;
	}

	EventType MouseScrolledEvent::GetEventType() const
	{
		return EventType::MouseScrolled;
	}

	EventCategory MouseScrolledEvent::GetEventCategory() const
	{
		return EventCategory::Mouse | EventCategory::Input;
	}
}
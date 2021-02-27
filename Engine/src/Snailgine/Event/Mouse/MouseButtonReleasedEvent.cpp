#include "MouseButtonReleasedEvent.hpp"

namespace sn
{
	MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseCode p_Button)
		: MouseButtonEvent(p_Button)
	{

	}

	EventType MouseButtonReleasedEvent::GetEventType() const
	{
		return EventType::MouseButtonReleased;
	}
}
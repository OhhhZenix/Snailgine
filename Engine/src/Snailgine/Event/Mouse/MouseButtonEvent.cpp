#include "MouseButtonEvent.hpp"

namespace sn
{

	MouseButtonEvent::MouseButtonEvent(MouseCode p_Button)
	{
		m_Button = p_Button;
	}

	MouseCode MouseButtonEvent::GetButton() const
	{
		return m_Button;
	}

	EventCategory MouseButtonEvent::GetEventCategory() const
	{
		return EventCategory::Mouse | EventCategory::MouseButton | EventCategory::Input;
	}
}
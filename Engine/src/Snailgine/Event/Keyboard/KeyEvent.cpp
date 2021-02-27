#include "KeyEvent.hpp"

namespace sn
{
	KeyEvent::KeyEvent(KeyCode p_KeyCode)
	{
		m_KeyCode = p_KeyCode;
	}

	EventCategory KeyEvent::GetEventCategory() const
	{
		return EventCategory::Keyboard | EventCategory::Input;
	}

	KeyCode KeyEvent::GetKeyCode() const
	{
		return m_KeyCode;
	}
}
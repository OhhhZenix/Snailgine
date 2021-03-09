#include "Snailgine/Event/Keyboard/KeyPressedEvent.hpp"

namespace sn
{
    KeyPressedEvent::KeyPressedEvent(KeyCode p_KeyCode, uint16_t p_RepeatCount)
            : KeyEvent(p_KeyCode)
    {
        m_RepeatCount = p_RepeatCount;
    }

    EventType KeyPressedEvent::GetEventType() const
    {
        return EventType::KeyPressed;
    }

    uint16_t KeyPressedEvent::GetRepeatCount() const
    {
        return m_RepeatCount;
    }
}
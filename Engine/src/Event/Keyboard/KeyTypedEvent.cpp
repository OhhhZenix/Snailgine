#include "Snailgine/Event/Keyboard/KeyTypedEvent.hpp"

namespace sn
{
    KeyTypedEvent::KeyTypedEvent(KeyCode p_KeyCode)
            : KeyEvent(p_KeyCode)
    {

    }

    EventType KeyTypedEvent::GetEventType() const
    {
        return EventType::KeyTyped;
    }
}
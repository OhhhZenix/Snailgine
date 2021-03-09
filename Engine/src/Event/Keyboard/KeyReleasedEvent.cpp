#include "Snailgine/Event/Keyboard/KeyReleasedEvent.hpp"

namespace sn
{
    KeyReleasedEvent::KeyReleasedEvent(KeyCode p_KeyCode)
            : KeyEvent(p_KeyCode)
    {

    }

    EventType KeyReleasedEvent::GetEventType() const
    {
        return EventType::KeyReleased;
    }
}
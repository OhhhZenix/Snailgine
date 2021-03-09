#include "Snailgine/Event/Mouse/MouseButtonPressedEvent.hpp"

namespace sn
{
    MouseButtonPressedEvent::MouseButtonPressedEvent(MouseCode p_Button)
            : MouseButtonEvent(p_Button)
    {

    }

    EventType MouseButtonPressedEvent::GetEventType() const
    {
        return EventType::MouseButtonPressed;
    }
}
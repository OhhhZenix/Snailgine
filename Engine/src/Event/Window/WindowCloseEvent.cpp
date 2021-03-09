#include "Snailgine/Event/Window/WindowCloseEvent.hpp"

namespace sn
{
    WindowCloseEvent::~WindowCloseEvent() = default;

    EventType WindowCloseEvent::GetEventType() const
    {
        return EventType::WindowClose;
    }

    EventCategory WindowCloseEvent::GetEventCategory() const
    {
        return EventCategory::Window;
    }
}
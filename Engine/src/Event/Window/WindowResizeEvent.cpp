#include "Snailgine/Event/Window/WindowResizeEvent.hpp"

namespace sn
{
    WindowResizeEvent::WindowResizeEvent(uint32_t p_Width, uint32_t p_Height)
    {
        m_Width = p_Width;
        m_Height = p_Height;
    }

    // formattings@off
    WindowResizeEvent::~WindowResizeEvent() = default;

    EventType WindowResizeEvent::GetEventType() const
    {
        return EventType::WindowResize;
    }

    EventCategory WindowResizeEvent::GetEventCategory() const
    {
        return EventCategory::Window;
    }

    uint32_t WindowResizeEvent::GetWidth() const
    {
        return m_Width;
    }

    uint32_t WindowResizeEvent::GetHeight() const
    {
        return m_Height;
    }
}
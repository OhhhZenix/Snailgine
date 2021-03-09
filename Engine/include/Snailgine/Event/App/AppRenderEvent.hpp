#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn
{
    class AppRenderEvent : public Event
    {
        public:
            ~AppRenderEvent() override = default;

            [[nodiscard]] EventType GetEventType() const override;

            [[nodiscard]] EventCategory GetEventCategory() const override;
    };
}
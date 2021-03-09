#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn
{
    class AppUpdateEvent : public Event
    {
        public:
            ~AppUpdateEvent() override = default;

            EventType GetEventType() const override;

            EventCategory GetEventCategory() const override;
    };
}
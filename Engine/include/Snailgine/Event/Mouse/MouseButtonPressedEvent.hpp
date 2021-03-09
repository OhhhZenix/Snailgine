#pragma once

#include "Snailgine/Event/Mouse/MouseButtonEvent.hpp"

namespace sn
{
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
        public:
            explicit MouseButtonPressedEvent(MouseCode p_Button);

            [[nodiscard]] EventType GetEventType() const override;
    };
}
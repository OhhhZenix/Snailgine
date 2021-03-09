#pragma once

#include "KeyEvent.hpp"

namespace sn
{
    class KeyReleasedEvent : public KeyEvent
    {
        public:
            explicit KeyReleasedEvent(KeyCode p_KeyCode);

            [[nodiscard]] EventType GetEventType() const override;
    };
}
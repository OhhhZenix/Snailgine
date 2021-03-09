#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn
{
    class EventBaseFunction
    {
        private:
            virtual void Call(Event& p_Event) = 0;

        public:
            virtual ~EventBaseFunction() = default;

            void Execute(Event& p_Event);
    };
}
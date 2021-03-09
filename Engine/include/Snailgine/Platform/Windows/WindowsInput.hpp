#pragma once

#include "Snailgine/Core/Input.hpp"

namespace sn
{
    class WindowsInput : public Input
    {
        protected:
            [[nodiscard]] bool IsKeyPressedImpl(int p_KeyCode) const override;

            [[nodiscard]] bool IsMouseButtonPressedImpl(int p_Button) const override;

            [[nodiscard]] Vec2f GetMousePositionImpl() const override;
    };
}
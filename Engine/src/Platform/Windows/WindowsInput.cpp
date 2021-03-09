#include "WindowsInput.hpp"

#include "Snailgine/Core/Application.hpp"

namespace sn
{
    bool WindowsInput::IsKeyPressedImpl(int p_KeyCode) const
    {
        return false;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int p_Button) const
    {
        return false;
    }
}
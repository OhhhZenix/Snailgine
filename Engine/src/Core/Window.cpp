#include "Snailgine/Core/Window.hpp"

#include "Snailgine/Core/Log.hpp"

#if defined(SN_PLATFORM_WINDOW)

#include "Snailgine/Platform/Windows/WindowsWindow.hpp"

#endif

namespace sn
{
    WindowSettings::WindowSettings(const std::string& p_Title, uint32_t p_Width, uint32_t p_Height, bool p_Vsync)
    {
        Title = p_Title;
        Width = p_Width;
        Height = p_Height;
        Vsync = p_Vsync;
    }

    Window*Window::Create(const WindowSettings& p_Settings)
    {
#if defined(SN_PLATFORM_WINDOW)
        return new WindowsWindow(p_Settings);
#else
        SN_LOG_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif
    }
}

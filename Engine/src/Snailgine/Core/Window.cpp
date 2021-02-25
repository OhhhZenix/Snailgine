#include "Window.hpp"

#include "Snailgine/Core/Log.hpp"

#if defined(SN_PLATFORM_WINDOW)
#include "Snailgine/Platform/Windows/WindowsWindow.hpp"
#endif

namespace sn
{
	Window* Window::Create()
	{
#if defined(SN_PLATFORM_WINDOW)
		return new WindowsWindow();
#else
		SN_LOG_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}

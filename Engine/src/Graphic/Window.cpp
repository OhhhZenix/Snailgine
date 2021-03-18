#include "Snailgine/Graphic/Window.hpp"

#include <Snailgine/GLFW/GLFWWindow.hpp>

namespace sn {

Window* Window::create_window(const WindowSettings& p_settings) {
#if defined(SN_PLATFORM_WINDOW)
	return new GLFWWindow(p_settings);
#else
	SN_LOG_ASSERT(false, "Windowing not supported!")
	return nullptr;
#endif
}

} // namespace sn
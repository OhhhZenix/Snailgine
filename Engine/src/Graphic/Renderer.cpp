#include "Snailgine/Graphic/Renderer.hpp"

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include <Snailgine/Core/Log.hpp>

namespace sn {

static const bgfx::ViewId s_renderer_id = 0;
static bool s_renderer_init = false;

void Renderer::init(Window& p_window) {
	if (s_renderer_init) {
		SN_LOG_ASSERT(false, "Renderer already initialized!")
		return;
	}

	auto l_handle = static_cast<GLFWwindow*>(p_window.get_handle());

	// Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
	// Most graphics APIs must be used on the same thread that created the window.
	bgfx::renderFrame();

	// Initialize bgfx using the native window handle and window resolution.
	bgfx::Init l_info;

#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	l_info.platformData.ndt = glfwGetX11Display();
	l_info.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
	l_info.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	l_info.platformData.nwh = glfwGetWin32Window(l_handle);
#endif

	int width, height;
	glfwGetWindowSize(l_handle, &width, &height);
	l_info.resolution.width = (uint32_t)width;
	l_info.resolution.height = (uint32_t)height;
	l_info.resolution.reset = BGFX_RESET_VSYNC;

	int l_success = bgfx::init(l_info);
	SN_LOG_ASSERT(l_success, "Could not initialize bgfx!")

	set_clear_option(BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH);
	set_viewport(p_window.get_settings().width, p_window.get_settings().height);

	s_renderer_init = true;
}

void Renderer::shutdown() {
	if (!s_renderer_init) {
		SN_LOG_ASSERT(false, "Renderer already uninitialized!")
		return;
	}
	bgfx::shutdown();
	s_renderer_init = false;
}

void Renderer::set_viewport(uint32_t p_width, uint32_t p_height) {
	bgfx::setViewRect(s_renderer_id, 0, 0, p_width, p_height);
}

void Renderer::set_clear_option(uint16_t p_flags) {
	bgfx::setViewClear(s_renderer_id, p_flags);
}

void Renderer::clear() {
	bgfx::touch(s_renderer_id);
}

void Renderer::swap_buffers() {
	bgfx::frame();
}

} // namespace sn
#pragma once

#include <Snailgine/Graphic/Window.hpp>

namespace sn {
class Renderer {
public:
	static void init(Window& p_window);

	static void shutdown();

	static void set_viewport(uint32_t p_width, uint32_t p_height);

	static void set_clear_option(uint16_t p_flags);

	static void clear();

	static void swap_buffers();
};
} // namespace sn
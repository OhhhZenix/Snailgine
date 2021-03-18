#pragma once

#include <Snailgine/Core/Base.hpp>

namespace sn {

struct WindowSettings {
	std::string title = "Snailgine App";
	uint32_t width = 1280;
	uint32_t height = 720;
};

class Window {
public:
	static Window* create_window(const WindowSettings& p_settings = WindowSettings());

	virtual ~Window() = default;

	virtual void process_update() = 0;

	virtual void* get_handle() = 0;

	virtual const WindowSettings& get_settings() const = 0;
};

} // namespace sn
#pragma once

#include <Snailgine/Graphic/Window.hpp>

namespace sn {

class GLFWWindow : public Window {
private:
	void* m_handle;
	WindowSettings m_settings;

public:
	GLFWWindow(const WindowSettings& p_settings);

	~GLFWWindow() override;

	void process_update() override;

	void* get_handle() override;

	const WindowSettings& get_settings() const override;
};

} // namespace sn
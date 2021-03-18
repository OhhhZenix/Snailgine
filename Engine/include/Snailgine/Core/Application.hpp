#pragma once

#include <Snailgine/Event/Window/WindowCloseEvent.hpp>
#include <Snailgine/Graphic/Window.hpp>
#include <Snailgine/Layer/LayerStack.hpp>

namespace sn {

class Application {
private:
	static Application* s_instance;
	Window* m_window;
	LayerStack m_layer_stack;
	bool m_running;
	bool m_minimized;

public:
	Application();

	virtual ~Application();

	static Application& instance();

private:
	void process_render();

	void process_update();

	void on_window_close_event(const WindowCloseEvent& p_event);

	// void on_window_resize_event(WindowResizeEvent& p_event);

public:
	void run();

	bool is_running() const;

	Window& get_window();

	void push_layer(Layer* p_layer);

	void push_overlay(Layer* p_overlay);

public:
	// Copy construct
	Application(Application const&) = delete;

	// Move construct
	Application(Application&&) = delete;

	// Copy assign
	Application& operator=(Application const&) = delete;

	// Move assign
	Application& operator=(Application&&) = delete;
};

// To be defined by client
extern Application* create_application();

} // namespace sn

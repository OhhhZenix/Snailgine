#include "Snailgine/Core/Application.hpp"

#include <bgfx/platform.h>

#include <Snailgine/Core/Log.hpp>
#include <Snailgine/Event/EventBus.hpp>
#include <Snailgine/Graphic/Renderer.hpp>

namespace sn {

Application* Application::s_instance = nullptr;

Application::Application() {
	SN_LOG_ASSERT(!s_instance, "Application already exists!")
	m_window = Window::create_window();
	m_running = true;
	m_minimized = false;
	s_instance = this;

	EventBus::init();

	SN_BIND_EVENT(WindowCloseEvent, &Application::on_window_close_event)
}

Application::~Application() {
	EventBus::shutdown();
	delete m_window;
}

Application& Application::instance() {
	return *s_instance;
}

void Application::process_render() {
	Renderer::init(*m_window);
	const WindowSettings& l_settings = m_window->get_settings();
	while (m_running) {
		if (m_minimized) {
			continue;
		}
		Renderer::set_viewport(l_settings.width, l_settings.height);
		Renderer::clear();
		//
		const bgfx::Stats* stats = bgfx::getStats();
		bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
		bgfx::setDebug(BGFX_DEBUG_STATS);
		Renderer::swap_buffers();
	}

	Renderer::shutdown();
}

void Application::process_update() {
	m_window->process_update();
}

void Application::on_window_close_event(const WindowCloseEvent& p_event) {
	m_running = false;
}

void Application::run() {
	float l_delta_time = 1.0f / 60.0f;
	std::thread l_renderer_thread(&Application::process_render, this);
	l_renderer_thread.detach();
	while (m_running) {
		if (m_minimized) {
			continue;
		}
		auto l_start = std::chrono::high_resolution_clock::now();
		printf("%f\n", l_delta_time);
		process_update();
		auto l_stop = std::chrono::high_resolution_clock::now();
		l_delta_time = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(l_stop - l_start).count();
	}
	if (l_renderer_thread.joinable()) {
		l_renderer_thread.join();
	}
}

bool Application::is_running() const {
	return m_running;
}

Window& Application::get_window() {
	return *m_window;
}
void Application::push_layer(Layer* p_layer) {
	m_layer_stack.push_layer(p_layer);
	p_layer->on_attach();
}

void Application::push_overlay(Layer* p_overlay) {
	m_layer_stack.push_overlay(p_overlay);
	p_overlay->on_attach();
}

} // namespace sn

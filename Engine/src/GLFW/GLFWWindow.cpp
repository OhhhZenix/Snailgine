#include "Snailgine/GLFW/GLFWWindow.hpp"

#include <GLFW/glfw3.h>

#include <Snailgine/Core/Log.hpp>
#include <Snailgine/Event/EventBus.hpp>
#include <Snailgine/Event/Window/WindowCloseEvent.hpp>

namespace sn {

static uint8_t s_window_count = 0;

void glfw_error_callback(int p_error, const char* p_description) {
	SN_LOG_ERROR("GLFW ERROR:")
	SN_LOG_ERROR(" Error Code: {}", p_error)
	SN_LOG_ERROR(" Error Description: {}", p_description)
}

void glfw_window_close_callback(GLFWwindow* window) {
	WindowCloseEvent l_event = WindowCloseEvent();
	EventBus::publish(l_event);
}

GLFWWindow::GLFWWindow(const WindowSettings& p_settings) {
	m_settings = p_settings;

	SN_LOG_INFO("Creating a window with title='{}' width={} height={}", m_settings.title, m_settings.width, m_settings.height)

	glfwSetErrorCallback(glfw_error_callback);

	if (s_window_count == 0) {
		int l_success = glfwInit();
		SN_LOG_ASSERT(l_success, "Could not initialize GLFW!")
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	m_handle = glfwCreateWindow(m_settings.width, m_settings.height, m_settings.title.c_str(), nullptr, nullptr);
	SN_LOG_ASSERT(m_handle, "Could not create a window!")

	auto l_glfw_window = static_cast<GLFWwindow*>(m_handle);
	glfwSetWindowCloseCallback(l_glfw_window, glfw_window_close_callback);

	s_window_count++;
}

GLFWWindow::~GLFWWindow() {
	glfwDestroyWindow(static_cast<GLFWwindow*>(m_handle));
	s_window_count--;

	if (s_window_count == 0) {
		glfwTerminate();
	}
}

void GLFWWindow::process_update() {
	glfwPollEvents();
}

void* GLFWWindow::get_handle() {
	return m_handle;
}

const WindowSettings& GLFWWindow::get_settings() const {
	return m_settings;
}

} // namespace sn
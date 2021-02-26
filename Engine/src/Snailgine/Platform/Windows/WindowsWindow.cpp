#include "WindowsWindow.hpp"

#include "Snailgine/Event/EventBus.hpp"
#include "Snailgine/Event/Window/WindowCloseEvent.hpp"
#include "Snailgine/Event/Window/WindowResizeEvent.hpp"

namespace sn
{
	void ErrorCallback(int p_Code, const char* p_Description)
	{
		SN_LOG_ERROR("GLFW Error code={0} description={1}", p_Code, p_Description);
	}

	void WindowCloseCallback([[maybe_unused]] GLFWwindow* p_Window)
	{
		WindowCloseEvent f_Event = WindowCloseEvent();
		EventBus::Instance().Publish(f_Event);
	}

	void WindowSizeCallback(GLFWwindow* p_Window, int32_t p_Width, int32_t p_Height)
	{
		auto* f_Settings = static_cast<WindowSettings*>(glfwGetWindowUserPointer(p_Window));
		f_Settings->Width = p_Width;
		f_Settings->Height = p_Height;
		WindowResizeEvent f_Event = WindowResizeEvent(p_Width, p_Height);
		EventBus::Instance().Publish(f_Event);
	}

	WindowsWindow::WindowsWindow(const WindowSettings& p_Settings)
	{
		m_Handle = nullptr;
		m_Context = nullptr;
		m_Settings = p_Settings;
	}

	WindowsWindow::~WindowsWindow()
	{
		delete m_Context;
		glfwDestroyWindow(static_cast<GLFWwindow*>(m_Handle));
		glfwTerminate();
	}

	void WindowsWindow::Init()
	{
		SN_PROFILE_FUNCTION();

		// Tries to initialize GLFW, but if fail it will exit the app
		if (!glfwInit())
		{
			SN_LOG_ASSERT(false, "Could not initialize glfw!");
			std::exit(EXIT_FAILURE);
		}

		glfwSetErrorCallback(ErrorCallback);

		// Tries to create a window
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		m_Handle = glfwCreateWindow(m_Settings.Width, m_Settings.Height, m_Settings.Title.c_str(), nullptr, nullptr);

		if (m_Handle == nullptr)
		{
			glfwTerminate();
			SN_LOG_ASSERT(false, "Could not create window!");
			std::exit(EXIT_FAILURE);
		}

		// Set user pointer
		glfwSetWindowUserPointer(static_cast<GLFWwindow*>(m_Handle), &m_Settings);

		// Makes a graphic context for the window
		m_Context = Context::Create(m_Handle);
		m_Context->Init();
		// SetVsync(m_Settings.Vsync);

		// Callbacks
		glfwSetWindowCloseCallback(static_cast<GLFWwindow*>(m_Handle), WindowCloseCallback);
		glfwSetWindowSizeCallback(static_cast<GLFWwindow*>(m_Handle), WindowSizeCallback);
	}

	void WindowsWindow::ProcessUpdate()
	{
		SN_PROFILE_FUNCTION();

		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void* WindowsWindow::GetHandle()
	{
		return m_Handle;
	}

	uint32_t WindowsWindow::GetWidth() const
	{
		return m_Settings.Width;
	}

	uint32_t WindowsWindow::GetHeight() const
	{
		return m_Settings.Height;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Settings.Vsync;
	}

	void WindowsWindow::SetVSync(bool p_Enabled)
	{
		if (p_Enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Settings.Vsync = p_Enabled;
	}
}
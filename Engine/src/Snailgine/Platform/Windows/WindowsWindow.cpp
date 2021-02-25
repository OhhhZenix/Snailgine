#include "WindowsWindow.hpp"

#include "Snailgine/Core/Log.hpp"

namespace sn
{
	WindowsWindow::WindowsWindow()
	{
		m_Handle = nullptr;
		m_Context = nullptr;
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

		// Tries to create a window
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		m_Handle = glfwCreateWindow(1280, 720, "Hello World", nullptr, nullptr);

		if (m_Handle == nullptr)
		{
			glfwTerminate();
			SN_LOG_ASSERT(false, "Could not create window!");
			std::exit(EXIT_FAILURE);
		}

		// Makes a graphic context for the window
		m_Context = Context::Create(m_Handle);
		m_Context->Init();
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
}
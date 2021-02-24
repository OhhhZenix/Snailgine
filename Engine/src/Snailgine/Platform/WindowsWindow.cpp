#include "WindowsWindow.hpp"

#include <iostream>

namespace sn
{
	WindowsWindow::WindowsWindow()
	= default;

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow((GLFWwindow*)m_Handle);
		glfwTerminate();
	}

	void WindowsWindow::Init()
	{
		// Tries to initialize GLFW, but if fail it will exit the app
		if (!glfwInit())
		{
			std::exit(EXIT_FAILURE);
		}

		// Tries to create a window
		m_Handle = glfwCreateWindow(1280, 720, "Hello World", nullptr, nullptr);

		// Makes a graphic context for the window
		glfwMakeContextCurrent(m_Handle);
		if (m_Handle == nullptr)
		{
			glfwTerminate();
			std::exit(EXIT_FAILURE);
		}
	}

	void WindowsWindow::ProcessUpdate()
	{
		// Polling the new events
		glfwPollEvents();
	}

	void* WindowsWindow::GetHandle()
	{
		return m_Handle;
	}
}
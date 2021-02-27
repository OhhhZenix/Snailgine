#include "WindowsWindow.hpp"

#include "Snailgine/Event/EventBus.hpp"
#include "Snailgine/Event/Window/WindowCloseEvent.hpp"
#include "Snailgine/Event/Window/WindowResizeEvent.hpp"
#include "Snailgine/Event/Keyboard/KeyPressedEvent.hpp"
#include "Snailgine/Event/Keyboard/KeyReleasedEvent.hpp"
#include "Snailgine/Event/Keyboard/KeyTypedEvent.hpp"
#include "Snailgine/Event/Mouse/MouseButtonPressedEvent.hpp"
#include "Snailgine/Event/Mouse/MouseButtonReleasedEvent.hpp"
#include "Snailgine/Event/Mouse/MouseScrolledEvent.hpp"
#include "Snailgine/Event/Mouse/MouseMovedEvent.hpp"

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

	void KeyCallback(GLFWwindow* p_Window, int p_Key, int p_Scancode, int p_Action, int p_Mods)
	{
		switch (p_Action)
		{
		case GLFW_PRESS:
		{
			KeyPressedEvent f_Event = KeyPressedEvent(static_cast<KeyCode>(p_Key), 0);
			EventBus::Instance().Publish(f_Event);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent f_Event = KeyReleasedEvent(static_cast<KeyCode>(p_Key));
			EventBus::Instance().Publish(f_Event);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyPressedEvent f_Event = KeyPressedEvent(static_cast<KeyCode>(p_Key), 1);
			EventBus::Instance().Publish(f_Event);
			break;
		}
		default:
			break;
		}
	}

	void CharCallback(GLFWwindow* p_Window, unsigned int p_Keycode)
	{
		KeyTypedEvent f_Event = KeyTypedEvent(static_cast<KeyCode>(p_Keycode));
		EventBus::Instance().Publish(f_Event);
	}

	void MouseButtonCallback(GLFWwindow* p_Window, int p_Button, int p_Action, int p_Mods)
	{
		switch (p_Action)
		{
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent f_Event = MouseButtonPressedEvent(static_cast<MouseCode>(p_Button));
			EventBus::Instance().Publish(f_Event);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent f_Event = MouseButtonReleasedEvent(static_cast<MouseCode>(p_Button));
			EventBus::Instance().Publish(f_Event);
			break;
		}
		default:
			break;
		}
	}

	void ScrollCallback(GLFWwindow* p_Window, double p_XOffset, double p_YOffset)
	{
		MouseScrolledEvent f_Event = MouseScrolledEvent(static_cast<float>(p_XOffset), static_cast<float>(p_YOffset));
		EventBus::Instance().Publish(f_Event);
	}

	void CursorPosCallback(GLFWwindow* p_Window, double p_X, double p_Y)
	{
		MouseMovedEvent f_Event = MouseMovedEvent((float)(p_X), (float)(p_Y));
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
		glfwSetKeyCallback(static_cast<GLFWwindow*>(m_Handle), KeyCallback);
		glfwSetCharCallback(static_cast<GLFWwindow*>(m_Handle), CharCallback);
		glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(m_Handle), MouseButtonCallback);
		glfwSetScrollCallback(static_cast<GLFWwindow*>(m_Handle), ScrollCallback);
		glfwSetCursorPosCallback(static_cast<GLFWwindow*>(m_Handle), CursorPosCallback);
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
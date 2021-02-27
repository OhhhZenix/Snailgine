#include "WindowsInput.hpp"

#include <GLFW/glfw3.h>
#include "Snailgine/Core/Application.hpp"

namespace sn
{
	bool WindowsInput::IsKeyPressedImpl(int p_KeyCode) const
	{
		auto* f_Window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetHandle());
		auto f_State = glfwGetKey(f_Window, p_KeyCode);
		return f_State == GLFW_PRESS || f_State == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int p_Button) const
	{
		auto* f_Window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetHandle());
		auto f_State = glfwGetMouseButton(f_Window, p_Button);
		return f_State == GLFW_PRESS;
	}

	Vec2f WindowsInput::GetMousePositionImpl() const
	{
		auto* f_Window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetHandle());
		double f_X, f_Y;
		glfwGetCursorPos(f_Window, &f_X, &f_Y);
		return Vec2f(static_cast<float>(f_X), static_cast<float>(f_Y));
	}
}
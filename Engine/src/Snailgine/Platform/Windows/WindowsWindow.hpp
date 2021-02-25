#pragma once

#include <GLFW/glfw3.h>
#include "Snailgine/Core/Window.hpp"
#include "Snailgine/Graphic/Context.hpp"

namespace sn
{
	class WindowsWindow : public Window
	{
	 private:
		GLFWwindow* m_Handle;
		Context* m_Context;

	 public:
		WindowsWindow();

		~WindowsWindow();

		void Init() override;

		void ProcessUpdate() override;

		void* GetHandle() override;
	};
}
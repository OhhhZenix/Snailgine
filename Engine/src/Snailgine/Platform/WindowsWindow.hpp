#pragma once

#include <GLFW/glfw3.h>
#include "Snailgine/Core/Window.hpp"

namespace sn
{
	class WindowsWindow : public Window
	{
	 private:
		GLFWwindow* m_Handle;

	 public:
		WindowsWindow();

		~WindowsWindow();

		void Init() override;

		void ProcessUpdate() override;

		void* GetHandle() override;
	};
}
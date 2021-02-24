#pragma once

#include <GLFW/glfw3.h>
#include "Snailgine/Core/Window.hpp"

namespace sn
{
	class WindowWindows : public Window
	{
	 private:
		GLFWwindow* m_Handle;

	 public:
		WindowWindows();

		~WindowWindows();

		void Init() override;

		void ProcessUpdate() override;

		void* GetHandle() override;
	};
}
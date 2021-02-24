#include "Application.hpp"

#include "Snailgine/Graphic/Renderer.hpp"

namespace sn
{
	Application::Application()
	{

	}

	Application& Application::Instance()
	{
		static Application s_Instance;
		return s_Instance;
	}

	void Application::Init()
	{
		m_Window->Init();
	}

	void Application::Run()
	{
		while (m_Running) {
			RenderCommand::SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			RenderCommand::Clear();
		}
	}
}
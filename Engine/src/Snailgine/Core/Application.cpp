#include "Application.hpp"

#include "Snailgine/Core/Base.hpp"

namespace sn
{
	void Init()
	{
		Log::Init();
		Application::Instance().Init();
		SN_LOG_INFO("Initialized all systems...");
	}

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
		// m_Window->Init();
	}

	void Application::Run()
	{
		while (m_Running) {
			// RenderCommand::SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			// RenderCommand::Clear();
		}
	}
}
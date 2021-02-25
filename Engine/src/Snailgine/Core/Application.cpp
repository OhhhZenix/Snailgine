#include "Application.hpp"

#include "Snailgine/Core/Base.hpp"
#include "Snailgine/Core/Window.hpp"
#include "Snailgine/Graphic/Renderer.hpp"

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
		m_Window = Window::Create();
		m_Running = true;
	}

	Application::~Application()
	{
		Renderer::Shutdown();
		delete m_Window;
	}

	Application& Application::Instance()
	{
		static Application s_Instance;
		return s_Instance;
	}

	void Application::Init()
	{
		m_Window->Init();
		Renderer::Init();
	}

	void Application::Run()
	{
		while (m_Running) {
			RenderCommand::SetClearColor(0.0f, 0.0f, 1.0f, 1.0f);
			RenderCommand::Clear();
			m_Window->ProcessUpdate();
		}
	}
}
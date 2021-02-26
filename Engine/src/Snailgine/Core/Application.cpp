#include "Application.hpp"

#include "Snailgine/Event/EventBus.hpp"
#include "Snailgine/Graphic/Renderer.hpp"
#include "Snailgine/ImGui/ImGuiLayer.hpp"

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
		m_Minimized = false;
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

		EventBus::Instance().Subscribe(this, &Application::OnWindowCloseEvent);
		EventBus::Instance().Subscribe(this, &Application::OnWindowResizeEvent);

		PushOverlay(new ImGuiLayer());
	}

	void Application::Run()
	{
		float f_DeltaTime = 0;
		while (m_Running)
		{
			// SN_LOG_INFO("DeltaTime: {}", f_DeltaTime);
			auto f_Start = std::chrono::high_resolution_clock::now();
			{
				RenderCommand::SetClearColor(0.64f, 0.64f, 0.64f, 1.0f);
				RenderCommand::Clear();

				if (!m_Minimized) {
					for (Layer* f_Layer : m_LayerStack.GetLayers()) {
						f_Layer->ProcessUpdate(f_DeltaTime);
					}
				}

				m_Window->ProcessUpdate();
			}
			auto f_Stop = std::chrono::high_resolution_clock::now();
			f_DeltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(f_Stop - f_Start)
				.count();
		}
	}

	void Application::PushLayer(Layer* p_Layer)
	{
		m_LayerStack.PushLayer(p_Layer);
		p_Layer->OnAttach();
	}

	void Application::PushOverlay(Layer* p_Overlay)
	{
		m_LayerStack.PushOverlay(p_Overlay);
		p_Overlay->OnAttach();
	}

	Window& Application::GetWindow()
	{
		return *m_Window;
	}

	void Application::OnWindowCloseEvent(WindowCloseEvent& p_Event)
	{
		SN_LOG_INFO("Application::OnWindowCloseEvent received {}", p_Event.GetEventType());
		m_Running = false;
	}

	void Application::OnWindowResizeEvent(WindowResizeEvent& p_Event)
	{
		SN_LOG_INFO("Application::OnWindowResizeEvent received {} with Width {}, Height {}", p_Event.GetEventType(), p_Event.GetWidth(), p_Event.GetHeight());

		if (p_Event.GetWidth() == 0 || p_Event.GetHeight() == 0)
		{
			m_Minimized = true;
			p_Event.SetCancelled(true);
			return;
		}

		m_Minimized = false;
		RenderCommand::SetViewport(0, 0, p_Event.GetWidth(), p_Event.GetHeight());
		p_Event.SetCancelled(true);
	}
}
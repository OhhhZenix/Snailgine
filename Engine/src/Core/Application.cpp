#include "Snailgine/Core/Application.hpp"

#include <glad/glad.h>
#include "Snailgine/Core/Input.hpp"
#include "Snailgine/Event/EventBus.hpp"
#include "Snailgine/Graphic/Renderer.hpp"

namespace sn
{
    struct Test {};

    void Init()
    {
        Log::Init();
        Input::Init();
        Application::Instance().Init();
        SN_LOG_INFO("Initialized all systems...");
    }

    Application::Application()
    {
        m_Window = Window::Create();
        //m_ImGuiLayer = new ImGuiLayer();
        m_Running = true;
        m_Minimized = false;
    }

    Application::~Application()
    {
        Input::Shutdown();
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
        Renderer::Init();

        EventBus::Instance().Subscribe(this,
                                       &Application::OnWindowCloseEvent);
        EventBus::Instance().Subscribe(this,
                                       &Application::OnWindowResizeEvent);

        // PushOverlay(m_ImGuiLayer);

        // Vertex Array
        // Vertex Buffer
        // Index Buffer
    }

    void Application::Run()
    {
        float f_DeltaTime = 0;
        while (m_Running)
        {
            auto f_Start = std::chrono::high_resolution_clock::now();
            {
                RenderCommand::SetClearColor(255,
                                             64,
                                             0,
                                             255);
                RenderCommand::Clear();

                if (!m_Minimized)
                {
                    if (!m_LayerStack.GetLayers().empty())
                    {
                        //m_ImGuiLayer->Begin();
                        for (Layer*f_Layer : m_LayerStack.GetLayers())
                        {
                            if (!f_Layer->IsEnabled())
                            {
                                continue;
                            }

                            f_Layer->ProcessUpdate(f_DeltaTime);

                            f_Layer->ProcessRender();
                        }
                        //m_ImGuiLayer->End();
                    }

/*
                    glBegin(GL_TRIANGLES);
                    glVertex2f(0, 0);
                    glColor3f(1.0f, 0.0f, 0.0f);
                    glVertex2f(1, 0);
                    glColor3f(0.0f, 1.0f, 0.0f);
                    glVertex2f(0, 1);
                    glColor3f(0.0f, 0.0f, 1.0f);
                    glEnd();*/
                }

                m_Window->ProcessUpdate();
            }
            auto f_Stop = std::chrono::high_resolution_clock::now();
            f_DeltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(f_Stop - f_Start)
                    .count();
        }
    }

    void Application::PushLayer(Layer*p_Layer)
    {
        m_LayerStack.PushLayer(p_Layer);
        p_Layer->OnAttach();
    }

    void Application::PushOverlay(Layer*p_Overlay)
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
        SN_LOG_INFO("Application::OnWindowCloseEvent received {}",
                    p_Event.GetEventType());
        m_Running = false;
    }

    void Application::OnWindowResizeEvent(WindowResizeEvent& p_Event)
    {
        SN_LOG_INFO("Application::OnWindowResizeEvent received {} with Width {}, Height {}",
                    p_Event
                            .GetEventType(),
                    p_Event.GetWidth(),
                    p_Event.GetHeight());

        if (p_Event.GetWidth() == 0 || p_Event.GetHeight() == 0)
        {
            m_Minimized = true;
            return;
        }

        m_Minimized = false;
        RenderCommand::SetViewport(0,
                                   0,
                                   p_Event.GetWidth(),
                                   p_Event.GetHeight());
    }
}
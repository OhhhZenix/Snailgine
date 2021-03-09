#include "Snailgine/Platform/Windows/WindowsWindow.hpp"

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
#include "Snailgine/Graphic/Renderer.hpp"

namespace sn
{
    static LRESULT __RPC_CALLEE WinProc(HWND win, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
            case WM_CLOSE:
            case WM_DESTROY:
                PostQuitMessage(0);
            default:
                return DefWindowProcA(win,
                                      msg,
                                      wparam,
                                      lparam);
        }
    }

    WindowsWindow::WindowsWindow(const WindowSettings& p_Settings)
    {
        SN_PROFILE_FUNCTION();

        SN_LOG_INFO("Creating a window with Title='{}' Width={} Height={}",
                    p_Settings.Title,
                    p_Settings.Width,
                    p_Settings.Height);

        // Set the settings
        m_Settings = p_Settings;

        WNDCLASSA f_WNDCLASSA = {0};
        f_WNDCLASSA.lpszClassName = "WinCoolClass";
        f_WNDCLASSA.lpfnWndProc = reinterpret_cast<WNDPROC>(WinProc);
        f_WNDCLASSA.hInstance = GetModuleHandle(nullptr);
        f_WNDCLASSA.hCursor = LoadCursor(nullptr,
                                         IDC_ARROW);

        RegisterClassA(&f_WNDCLASSA);

        m_Handle = CreateWindowExA(
                0,
                f_WNDCLASSA.lpszClassName,
                m_Settings.Title.c_str(),
                WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                m_Settings.Width,
                m_Settings.Height,
                nullptr,
                nullptr,
                nullptr,
                nullptr
        );

        // Makes a graphic context for the window
        m_Context = Context::Create(m_Handle);

        ShowWindow(m_Handle,
                   SW_SHOW);
        UpdateWindow(m_Handle);
    }

    WindowsWindow::~WindowsWindow()
    {
        delete m_Context;
        DestroyWindow(m_Handle);
    }

    void WindowsWindow::ProcessUpdate()
    {
        SN_PROFILE_FUNCTION();

        while (PeekMessage(&m_Event,
                           nullptr,
                           0,
                           0,
                           PM_REMOVE))
        {
            TranslateMessage(&m_Event);
            DispatchMessageA(&m_Event);

            if (m_Event.message == WM_QUIT)
            {
                WindowCloseEvent f_Event = WindowCloseEvent();
                EventBus::Instance().Publish(f_Event);
            }
        }

        m_Context->SwapBuffers();
    }

    void*WindowsWindow::GetHandle()
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
        m_Settings.Vsync = p_Enabled;
    }
}
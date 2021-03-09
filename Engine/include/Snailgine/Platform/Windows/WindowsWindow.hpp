#pragma once

#include <Windows.h>
#include "Snailgine/Core/Window.hpp"
#include "Snailgine/Graphic/Context.hpp"

namespace sn
{
    class WindowsWindow : public Window
    {
        private:
            Context*m_Context;
            HWND m_Handle;
            MSG m_Event;
            WindowSettings m_Settings;

        public:
            explicit WindowsWindow(const WindowSettings& p_Settings);

            ~WindowsWindow() override;

            void ProcessUpdate() override;

            void*GetHandle() override;

            [[nodiscard]] uint32_t GetWidth() const override;

            [[nodiscard]] uint32_t GetHeight() const override;

            [[nodiscard]] bool IsVSync() const override;

            void SetVSync(bool p_Enabled) override;
    };
}
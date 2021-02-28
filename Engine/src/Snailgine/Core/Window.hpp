#pragma once

#include "Snailgine/Core/Base.hpp"

namespace sn
{
	struct WindowSettings
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;
		bool Vsync;

		explicit WindowSettings(const std::string& p_Title = "Snailgine App", uint32_t p_Width = 1280, uint32_t p_Height = 720, bool p_Vsync = true);
	};

	class Window
	{
	 public:
		static Window* Create(const WindowSettings& p_Settings = WindowSettings());

		virtual ~Window() = default;

		virtual void ProcessUpdate() = 0;

		virtual void* GetHandle() = 0;

		[[nodiscard]] virtual uint32_t GetWidth() const = 0;

		[[nodiscard]] virtual uint32_t GetHeight() const = 0;

		[[nodiscard]] virtual bool IsVSync() const = 0;

		virtual void SetVSync(bool p_Enabled) = 0;
	};
}
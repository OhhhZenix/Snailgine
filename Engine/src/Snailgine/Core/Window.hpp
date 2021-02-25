#pragma once

namespace sn
{
	class Window
	{
	 public:
		static Window* Create();

		virtual ~Window() = default;

		virtual void Init() = 0;

		virtual void ProcessUpdate() = 0;

		virtual void* GetHandle() = 0;
	};
}
#pragma once

namespace sn
{
	class Window
	{
	 public:
		virtual void Init() = 0;

		virtual void ProcessUpdate();

		virtual void* GetHandle() = 0;
	};
}
#pragma once

namespace sn
{
	class Context
	{
	 public:
		static Context* Create(void* p_Window);

		virtual ~Context() = default;

		virtual void Init() = 0;

		virtual void SwapBuffers() = 0;
	};
}
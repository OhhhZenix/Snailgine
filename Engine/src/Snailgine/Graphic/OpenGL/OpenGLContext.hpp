#pragma once

#include "Snailgine/Graphic/Context.hpp"

namespace sn
{
	class OpenGLContext : public Context
	{
	 private:
		void* m_Window;

	 public:
		explicit OpenGLContext(void* p_Window);

		void Init() override;

		void SwapBuffers() override;
	};
}
#pragma once

#include "Snailgine/Core/Window.hpp"

namespace sn {
	 void Init();

	class Application
	{
	 private:
		Window* m_Window;
		bool m_Running;

	 private:
		Application();

		~Application();

	 public:
		static Application& Instance();

		void Init();

		void Run();
	};
};
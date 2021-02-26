#pragma once

#include "Snailgine/Core/Window.hpp"
#include "Snailgine/Event/Window/WindowCloseEvent.hpp"

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

	 private:
		void OnWindowCloseEvent(WindowCloseEvent* p_Event);

	 public:
		// Copy construct
		Application(Application const&) = delete;

		// Move construct
		Application(Application&&) = delete;

		// Copy assign
		Application& operator=(Application const&) = delete;

		// Move assign
		Application& operator=(Application&&) = delete;
	};
};
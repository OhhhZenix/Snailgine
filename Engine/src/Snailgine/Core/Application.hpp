#pragma once

#include "Snailgine/Core/Window.hpp"
#include "Snailgine/Event/Window/WindowCloseEvent.hpp"
#include "Snailgine/Event/Window/WindowResizeEvent.hpp"
#include "Snailgine/Layer/LayerStack.hpp"

namespace sn {
	 void Init();

	class Application
	{
	 private:
		Window* m_Window;
		LayerStack m_LayerStack;
		bool m_Running;
		bool m_Minimized;

	 private:
		Application();

		~Application();

	 public:
		static Application& Instance();

		void Init();

		void Run();

		void PushLayer(Layer* p_Layer);

		void PushOverlay(Layer* p_Overlay);

		Window& GetWindow();

	 private:
		void OnWindowCloseEvent(WindowCloseEvent& p_Event);

		void OnWindowResizeEvent(WindowResizeEvent& p_Event);

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
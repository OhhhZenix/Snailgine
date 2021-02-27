#pragma once

#include "Snailgine/Layer/Layer.hpp"
#include "Snailgine/Event/Mouse/MouseButtonPressedEvent.hpp"
#include "Snailgine/Event/Mouse/MouseButtonReleasedEvent.hpp"
#include "Snailgine/Event/Mouse/MouseMovedEvent.hpp"
#include "Snailgine/Event/Mouse/MouseScrolledEvent.hpp"
#include "Snailgine/Event/Keyboard/KeyPressedEvent.hpp"
#include "Snailgine/Event/Keyboard/KeyReleasedEvent.hpp"
#include "Snailgine/Event/Keyboard/KeyTypedEvent.hpp"
#include "Snailgine/Event/Window/WindowResizeEvent.hpp"

namespace sn
{
	class ImGuiLayer : public Layer
	{
	 public:
		~ImGuiLayer() override = default;

		void OnAttach() override;

		void OnDetach() override;

		void ProcessUpdate(float p_DeltaTime) override;

	 private:
		void OnMouseButtonPressedEvent(MouseButtonPressedEvent& p_Event);

		void OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& p_Event);

		void OnMouseMovedEvent(MouseMovedEvent& p_Event);

		void OnMouseScrolledEvent(MouseScrolledEvent& p_Event);

		void OnKeyPressedEvent(KeyPressedEvent& p_Event);

		void OnKeyReleasedEvent(KeyReleasedEvent& p_Event);

		void OnKeyTypedEvent(KeyTypedEvent& p_Event);

		void OnWindowResizeEvent(WindowResizeEvent& p_Event);
	};
}
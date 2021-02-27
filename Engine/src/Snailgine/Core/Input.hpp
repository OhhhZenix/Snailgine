#pragma once

#include "Snailgine/Math/Vec2.hpp"

namespace sn
{
	class Input
	{
	 private:
		static Input* s_Instance;

	 public:
		static void Init();

		static void Shutdown();

		static bool IsKeyPressed(int p_KeyCode);

		static bool IsMouseButtonPressed(int p_Button);

		static Vec2f GetMousePosition();

	 protected:
		Input() = default;

		virtual ~Input() = default;

		[[nodiscard]] virtual bool IsKeyPressedImpl(int p_KeyCode) const = 0;

		[[nodiscard]] virtual bool IsMouseButtonPressedImpl(int p_Button) const = 0;

		[[nodiscard]] virtual Vec2f GetMousePositionImpl() const = 0;

	 public:
		// Copy construct
		Input(Input const&) = delete;

		// Move construct
		Input(Input&&) = delete;

		// Copy assign
		Input& operator=(Input const&) = delete;

		// Move assign
		Input& operator=(Input&&) = delete;
	};
}
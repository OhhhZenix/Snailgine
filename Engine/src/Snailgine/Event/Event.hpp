#pragma once

#include "Snailgine/Core/Base.hpp"

namespace sn
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum class EventCategory
	{
		None = 0,
		Window = Bit(0),
		App = Bit(1),
		Keyboard = Bit(2),
		Mouse = Bit(3),
		MouseButton = Bit(4),
		Input = Bit(5)
	};

	EventCategory operator|(EventCategory p_Left, EventCategory p_Right);

	EventCategory operator&(EventCategory p_Left, EventCategory p_Right);

	EventCategory operator^(EventCategory p_Left, EventCategory p_Right);

	EventCategory& operator|=(EventCategory& p_Left, EventCategory p_Right);

	EventCategory& operator&=(EventCategory& p_Left, EventCategory p_Right);

	EventCategory& operator^=(EventCategory& p_Left, EventCategory p_Right);

	EventCategory operator~(EventCategory p_Category);

	class Event
	{
	 private:
		bool m_Cancelled;

	 public:
		Event();

		virtual ~Event() = default;

		[[nodiscard]] virtual EventType GetEventType() const = 0;

		[[nodiscard]] virtual EventCategory GetEventCategory() const = 0;

		[[nodiscard]] bool IsInCategory(EventCategory p_Category) const;

		[[nodiscard]] bool IsCancelled() const;

		void SetCancelled(bool p_Cancelled);
	};
}
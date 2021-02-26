#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn {
	class MouseMovedEvent : public Event
	{
	 private:
		float m_X;
		float m_Y;

	 public:
		MouseMovedEvent(float p_X, float p_Y);

		[[nodiscard]] EventType GetEventType() const override;

		[[nodiscard]] EventCategory GetEventCategory() const override;

		[[nodiscard]] float GetX() const;

		[[nodiscard]] float GetY() const;
	};
}
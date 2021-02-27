#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn
{
	class MouseScrolledEvent : public Event
	{
	 private:
		float m_XOffset;
		float m_YOffset;

	 public:
		MouseScrolledEvent(float p_XOffset, float p_YOffset);

		[[nodiscard]] float GetXOffset() const;

		[[nodiscard]] float GetYOffset() const;

		[[nodiscard]] EventType GetEventType() const override;

		[[nodiscard]] EventCategory GetEventCategory() const override;
	};
}
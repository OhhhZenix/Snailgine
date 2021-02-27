#pragma once

#include "Snailgine/Event/Event.hpp"
#include "Snailgine/Core/MouseCode.hpp"

namespace sn
{
	class MouseButtonEvent : public Event
	{
	 private:
		MouseCode m_Button;

	 protected:
		explicit MouseButtonEvent(MouseCode p_Button);

	 public:
		[[nodiscard]] MouseCode GetButton() const;

		[[nodiscard]] EventCategory GetEventCategory() const override;
	};
}
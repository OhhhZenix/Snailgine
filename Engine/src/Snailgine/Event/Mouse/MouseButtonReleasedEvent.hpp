#pragma once

#include "Snailgine/Event/Mouse/MouseButtonEvent.hpp"

namespace sn
{
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	 public:
		explicit MouseButtonReleasedEvent(MouseCode p_Button);

		[[nodiscard]] EventType GetEventType() const override;
	};
}
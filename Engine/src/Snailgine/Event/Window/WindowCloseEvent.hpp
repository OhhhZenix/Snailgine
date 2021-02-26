#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn
{
	class WindowCloseEvent : public Event
	{
	 public:
		~WindowCloseEvent() override;

		[[nodiscard]] EventType GetEventType() const override;

		[[nodiscard]] EventCategory GetEventCategory() const override;
	};
}
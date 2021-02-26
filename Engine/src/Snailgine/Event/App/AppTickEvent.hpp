#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn
{
	class AppTickEvent : public Event
	{
	 public:
		~AppTickEvent() override = default;

		EventType GetEventType() const override;

		EventCategory GetEventCategory() const override;
	};
}
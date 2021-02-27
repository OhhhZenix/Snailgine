#include "AppTickEvent.hpp"

namespace sn
{
	EventType AppTickEvent::GetEventType() const
	{
		return EventType::AppTick;
	}

	EventCategory AppTickEvent::GetEventCategory() const
	{
		return EventCategory::App;
	}
}
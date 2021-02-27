#include "AppUpdateEvent.hpp"

namespace sn
{
	EventType AppUpdateEvent::GetEventType() const
	{
		return EventType::AppUpdate;
	}

	EventCategory AppUpdateEvent::GetEventCategory() const
	{
		return EventCategory::App;
	}
}
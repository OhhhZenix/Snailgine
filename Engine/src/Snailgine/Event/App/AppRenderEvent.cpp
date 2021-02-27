#include "AppRenderEvent.hpp"

namespace sn
{
	EventType AppRenderEvent::GetEventType() const
	{
		return EventType::AppRender;
	}

	EventCategory AppRenderEvent::GetEventCategory() const
	{
		return EventCategory::App;
	}
}
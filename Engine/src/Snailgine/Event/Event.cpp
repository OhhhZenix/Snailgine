#include "Event.hpp"

namespace sn {
	EventCategory operator|(EventCategory p_Left, EventCategory p_Right)
	{
		return static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_Left) |
										   static_cast<std::underlying_type_t<EventCategory>>(p_Right));
	}

	EventCategory operator&(EventCategory p_Left, EventCategory p_Right)
	{
		return static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_Left) &
										   static_cast<std::underlying_type_t<EventCategory>>(p_Right));
	}

	EventCategory operator^(EventCategory p_Left, EventCategory p_Right)
	{
		return static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_Left) ^
										   static_cast<std::underlying_type_t<EventCategory>>(p_Right));
	}

	EventCategory &operator|=(EventCategory &p_Left, EventCategory p_Right)
	{
		p_Left = static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_Left) |
											 static_cast<std::underlying_type_t<EventCategory>>(p_Right));
		return p_Left;
	}

	EventCategory &operator&=(EventCategory &p_Left, EventCategory p_Right)
	{
		p_Left = static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_Left) &
											 static_cast<std::underlying_type_t<EventCategory>>(p_Right));
		return p_Left;
	}

	EventCategory &operator^=(EventCategory &p_Left, EventCategory p_Right)
	{
		p_Left = static_cast<EventCategory>(static_cast<std::underlying_type_t<EventCategory>>(p_Left) ^
											 static_cast<std::underlying_type_t<EventCategory>>(p_Right));
		return p_Left;
	}

	EventCategory operator~(EventCategory p_Category)
	{
		return static_cast<EventCategory>(~static_cast<std::underlying_type_t<EventCategory>>(p_Category));
	}

	bool Event::IsInCategory(EventCategory p_Category) const
	{
		return static_cast<bool>(GetEventCategory() & p_Category);
	}
}
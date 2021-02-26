#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn {
	class WindowCloseEvent : public Event
	{
	 public:
		~WindowCloseEvent();
	};
}
#pragma once

#include "KeyEvent.hpp"

namespace sn
{
	class KeyTypedEvent : public KeyEvent
	{
	 public:
		explicit KeyTypedEvent(KeyCode p_KeyCode);

		[[nodiscard]] EventType GetEventType() const override;
	};
}
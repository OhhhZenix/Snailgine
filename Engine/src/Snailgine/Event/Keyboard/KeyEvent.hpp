#pragma once

#include "Snailgine/Core/KeyCode.hpp"
#include "Snailgine/Event/Event.hpp"

namespace sn
{
	class KeyEvent : public Event
	{
	 private:
		KeyCode m_KeyCode;

	 public:
		explicit KeyEvent(KeyCode p_KeyCode);

		[[nodiscard]] EventCategory GetEventCategory() const override;

		[[nodiscard]] KeyCode GetKeyCode() const;
	};
}
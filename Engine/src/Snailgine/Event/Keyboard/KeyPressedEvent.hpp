#pragma once

#include "KeyEvent.hpp"

namespace sn
{
	class KeyPressedEvent : public KeyEvent
	{
	 private:
		uint16_t m_RepeatCount;

	 public:
		KeyPressedEvent(KeyCode p_KeyCode, uint16_t p_RepeatCount);

		[[nodiscard]] EventType GetEventType() const override;

		[[nodiscard]] uint16_t GetRepeatCount() const;
	};
}
#pragma once

#include "Snailgine/Event/Event.hpp"

namespace sn {
	class WindowResizeEvent : public Event
	{
	 private:
		uint32_t m_Width;
		uint32_t m_Height;

	 public:
		WindowResizeEvent(uint32_t p_Width, uint32_t p_Height);

		~WindowResizeEvent() override;

		[[nodiscard]] EventType GetEventType() const override;

		[[nodiscard]] EventCategory GetEventCategory() const override;

		[[nodiscard]] uint32_t GetWidth() const;

		[[nodiscard]] uint32_t GetHeight() const;
	};
}
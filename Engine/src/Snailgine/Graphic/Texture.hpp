#pragma once

namespace sn
{
	class Texture
	{
	 public:
		virtual ~Texture() = default;

		[[nodiscard]] virtual uint32_t GetWidth() const = 0;

		[[nodiscard]] virtual uint32_t GetHeight() const = 0;

		[[nodiscard]] virtual uint32_t GetRendererID() const = 0;

		virtual void SetData(void* p_Data, uint32_t p_Size) = 0;

		virtual void Bind(uint32_t p_Slot = 0) const = 0;

		virtual bool operator==(const Texture& p_Other) const = 0;
	};
}
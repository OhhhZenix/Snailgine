#pragma once

#include "Snailgine/Graphic/BufferElement.hpp"

namespace sn
{
	class BufferLayout
	{
	 private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride;

	 public:
		BufferLayout();

		BufferLayout(std::initializer_list<BufferElement> p_Elements);

		[[nodiscard]] uint32_t GetStride() const;

		[[nodiscard]] const std::vector<BufferElement>& GetElements() const;

		std::vector<BufferElement>::iterator Begin();

		std::vector<BufferElement>::iterator End();

		[[nodiscard]] std::vector<BufferElement>::const_iterator Begin() const;

		[[nodiscard]] std::vector<BufferElement>::const_iterator End() const;

	 private:
		void CalculateOffsetsAndStride();
	};
}
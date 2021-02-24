#pragma once

#include <cstdint>

namespace sn
{
	class IndexBuffer
	{
	 public:
		static IndexBuffer* Create(uint32_t* p_Indices, uint32_t p_Count);

		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;
	};
}
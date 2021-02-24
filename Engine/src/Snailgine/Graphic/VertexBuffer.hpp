#pragma once

#include <cstdint>

namespace sn
{
	class VertexBuffer
	{
	 public:
		static VertexBuffer* Create(float* p_Vertices, uint32_t p_Size);

		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;

		virtual void Unbind() = 0;
	};
}
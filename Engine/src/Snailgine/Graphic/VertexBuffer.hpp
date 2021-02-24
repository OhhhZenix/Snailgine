#pragma once

#include "Snailgine/PCH.hpp"
#include "Snailgine/Graphic/BufferLayout.hpp"

namespace sn
{
	// TODO: beyond 32 bit
	class VertexBuffer
	{
	 public:
		static VertexBuffer* Create(uint32_t p_Size);

		static VertexBuffer* Create(float* p_Vertices, uint32_t p_Size);

		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;

		virtual void Unbind() = 0;

		virtual void SetData(const void* data, uint32_t size) = 0;

		[[nodiscard]] virtual const BufferLayout* GetLayout() const = 0;

		virtual void SetLayout(BufferLayout* layout) = 0;
	};
}
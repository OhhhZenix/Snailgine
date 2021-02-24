#pragma once

#include "Snailgine/Graphic/IndexBuffer.hpp"
#include "Snailgine/Graphic/VertexBuffer.hpp"

namespace sn
{
	class VertexArray
	{
	 public:
		static VertexArray* Create();

		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(VertexBuffer* p_VertexBuffer) = 0;

		virtual void SetIndexBuffer(IndexBuffer* p_IndexBuffer) = 0;

		[[nodiscard]] virtual const std::vector<VertexBuffer*>& GetVertexBuffers() const = 0;

		[[nodiscard]] virtual const IndexBuffer& GetIndexBuffer() const = 0;
	};
}
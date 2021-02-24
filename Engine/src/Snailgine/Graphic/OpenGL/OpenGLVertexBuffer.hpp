#pragma once

#include "Snailgine/Graphic/VertexBuffer.hpp"

namespace sn
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	 private:
		uint32_t m_RendererID;

	 public:
		OpenGLVertexBuffer(float* p_Vertices, uint32_t p_Size);

		~OpenGLVertexBuffer() override;

		void Bind() override;

		void Unbind() override;
	};
}
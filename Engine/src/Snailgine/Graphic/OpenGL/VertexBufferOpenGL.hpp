#pragma once

#include "Snailgine/Graphic/VertexBuffer.hpp"

namespace sn
{
	class VertexBufferOpenGL : public VertexBuffer
	{
	 private:
		uint32_t m_RendererID;

	 public:
		VertexBufferOpenGL(float* p_Vertices, uint32_t p_Size);

		~VertexBufferOpenGL() override;

		void Bind() override;

		void Unbind() override;
	};
}
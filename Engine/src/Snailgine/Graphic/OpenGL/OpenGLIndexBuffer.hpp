#pragma once

#include "Snailgine/Graphic/IndexBuffer.hpp"

namespace sn
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	 public:
		OpenGLIndexBuffer(uint32_t* p_Indices, uint32_t p_Count);

		~OpenGLIndexBuffer() override;

		void Bind() const override;

		void Unbind() const override;

	 private:
		uint32_t m_RendererID;
	};
}
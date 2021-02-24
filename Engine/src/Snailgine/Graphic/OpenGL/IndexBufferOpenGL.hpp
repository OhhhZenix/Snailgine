#pragma once

#include "Snailgine/Graphic/IndexBuffer.hpp"

namespace sn
{
	class IndexBufferOpenGL : public IndexBuffer
	{
	 public:
		IndexBufferOpenGL(uint32_t* p_Indices, uint32_t p_Count);

		~IndexBufferOpenGL() override;

		void Bind() const override;

		void Unbind() const override;

	 private:
		uint32_t m_RendererID;
	};
}
#include "OpenGLVertexBuffer.hpp"

#include <glad/glad.h>

namespace sn {
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* p_Vertices, uint32_t p_Size)
	{
		glCreateBuffers(1, &m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, p_Size, p_Vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
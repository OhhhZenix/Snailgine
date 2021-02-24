#include "VertexBufferOpenGL.hpp"

#include <glad/glad.h>

namespace sn {
	VertexBufferOpenGL::VertexBufferOpenGL(float* p_Vertices, uint32_t p_Size)
	{
		glCreateBuffers(1, &m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, p_Size, p_Vertices, GL_STATIC_DRAW);
	}

	VertexBufferOpenGL::~VertexBufferOpenGL()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void VertexBufferOpenGL::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void VertexBufferOpenGL::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
#include "IndexBufferOpenGL.hpp"

#include <glad/glad.h>

namespace sn
{
	IndexBufferOpenGL::IndexBufferOpenGL(uint32_t* p_Indices, uint32_t p_Count)
	{
		glCreateBuffers(1, &m_RendererID);

		// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
		// Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state.
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, p_Count * sizeof(uint32_t), p_Indices, GL_STATIC_DRAW);
	}

	IndexBufferOpenGL::~IndexBufferOpenGL()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void IndexBufferOpenGL::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void IndexBufferOpenGL::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
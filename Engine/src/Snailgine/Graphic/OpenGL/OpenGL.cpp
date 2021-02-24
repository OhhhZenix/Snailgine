#include "OpenGL.hpp"

#include <glad/glad.h>

namespace sn
{
	void OpenGL::Init()
	{

	}

	void OpenGL::SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height)
	{
		glViewport(p_X, p_Y, p_Width, p_Height);
	}

	void OpenGL::SetClearColor(float p_R, float p_G, float p_B, float p_A)
	{
		glClearColor(p_R, p_G, p_B, p_A);
	}

	void OpenGL::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
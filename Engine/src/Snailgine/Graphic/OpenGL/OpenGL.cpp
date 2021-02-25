#include "OpenGL.hpp"

#include <glad/glad.h>

namespace sn
{
	void OpenGLMessageCallback(
		GLenum p_Source, GLenum p_Type, GLuint p_ID, GLenum p_Severity, GLsizei p_Length, const GLchar* p_Message, const void* p_UserParam)
	{
		switch (p_Severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:
			SN_LOG_CRITICAL(p_Message);
			return;
		case GL_DEBUG_SEVERITY_MEDIUM:
			SN_LOG_ERROR(p_Message);
			return;
		case GL_DEBUG_SEVERITY_LOW:
			SN_LOG_WARN(p_Message);
			return;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			SN_LOG_TRACE(p_Message);
			return;
		default:
			break;
		}
		SN_LOG_ASSERT(false, "Unknown severity level!");
	}

	void OpenGL::Init()
	{
		// SN_PROFILE_FUNCTION();

#if defined(SN_BUILD_DEBUG)
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback((GLDEBUGPROC)OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
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
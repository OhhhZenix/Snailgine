#include "OpenGLContext.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Snailgine/Core/Log.hpp"

namespace sn
{
	OpenGLContext::OpenGLContext(void* p_Window)
	{
		m_Window = p_Window;

		SN_LOG_ASSERT(p_Window, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		SN_PROFILE_FUNCTION();

		glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_Window));
		int f_Status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SN_LOG_ASSERT(f_Status, "Failed to initialize glad!");

		SN_LOG_INFO("OpenGL Info:");
		SN_LOG_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		SN_LOG_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		SN_LOG_INFO("  Version: {0}", glGetString(GL_VERSION));

		SN_LOG_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Snailgine requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		SN_PROFILE_FUNCTION();

		glfwSwapBuffers(static_cast<GLFWwindow*>(m_Window));
	}
}
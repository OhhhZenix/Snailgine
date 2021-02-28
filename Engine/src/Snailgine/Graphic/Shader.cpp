#include "Shader.hpp"

#include "Snailgine/Graphic/Renderer.hpp"
#include "Snailgine/Graphic/OpenGL/OpenGLShader.hpp"

namespace sn
{
	Shader* Shader::Create(const std::string& p_VertexPath, const std::string& p_FragmentPath)
	{
		switch (Renderer::GetAPI())
		{
		case GraphicAPI::OpenGL:
			return new OpenGLShader(p_VertexPath, p_FragmentPath);
		case GraphicAPI::Vulkan:
		case GraphicAPI::None:
			break;
		}

		SN_LOG_ASSERT(false, "Unknown/Unimplemented graphics api!");
		return nullptr;
	}
}
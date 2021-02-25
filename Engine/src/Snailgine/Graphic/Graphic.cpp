#include "Graphic.hpp"

#include "Snailgine/Core/Log.hpp"
#include "Snailgine/Graphic/OpenGL/OpenGL.hpp"

namespace sn
{
	GraphicAPI Graphic::s_API = GraphicAPI::OpenGL;

	Graphic* Graphic::Create()
	{
		switch (s_API)
		{
		case GraphicAPI::OpenGL:
			return new OpenGL();
		case GraphicAPI::Vulkan:
		case GraphicAPI::None:
		default:
			break;
		}

		SN_LOG_ASSERT(false, "Unknown/Unimplemented graphics api!");
		return nullptr;
	}

	GraphicAPI Graphic::GetAPI()
	{
		return s_API;
	}
}
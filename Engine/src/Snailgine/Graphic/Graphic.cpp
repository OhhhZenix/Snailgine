#include "Graphic.hpp"

namespace sn
{
	GraphicAPI Graphic::s_API = GraphicAPI::OpenGL;

	GraphicAPI Graphic::GetAPI()
	{
		return s_API;
	}

	Graphic* Graphic::Create()
	{
		switch (s_API)
		{
		case GraphicAPI::OpenGL:
			break;
		}
		return nullptr;
	}
}
#include "Renderer.hpp"

namespace sn
{
	void Renderer::Init()
	{
		RenderCommand::Init();
	}

	void Renderer::Shutdown()
	{
		RenderCommand::Shutdown();
	}

	GraphicAPI Renderer::GetAPI()
	{
		return Graphic::GetAPI();
	}
}
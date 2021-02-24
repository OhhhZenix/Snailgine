#include "RenderCommand.hpp"

#include "Snailgine/Graphic/OpenGL/OpenGL.hpp"

namespace sn
{
	Graphic* RenderCommand::s_Graphic = new OpenGL();

	void sn::RenderCommand::Init()
	{
		s_Graphic->Init();
	}

	void sn::RenderCommand::SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height)
	{
		s_Graphic->SetViewport(p_X, p_Y, p_Width, p_Height);
	}

	void sn::RenderCommand::SetClearColor(float p_R, float p_G, float p_B, float p_A)
	{
		s_Graphic->SetClearColor(p_R, p_G, p_B, p_A);
	}

	void sn::RenderCommand::Clear()
	{
		s_Graphic->Clear();
	}
}
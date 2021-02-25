#include "RenderCommand.hpp"

namespace sn
{
	Graphic* RenderCommand::s_Graphic = Graphic::Create();

	void RenderCommand::Init()
	{
		s_Graphic->Init();
	}

	void RenderCommand::Shutdown()
	{
		delete s_Graphic;
	}

	void RenderCommand::SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height)
	{
		s_Graphic->SetViewport(p_X, p_Y, p_Width, p_Height);
	}

	void RenderCommand::SetClearColor(float p_R, float p_G, float p_B, float p_A)
	{
		s_Graphic->SetClearColor(p_R, p_G, p_B, p_A);
	}

	void RenderCommand::Clear()
	{
		s_Graphic->Clear();
	}
}
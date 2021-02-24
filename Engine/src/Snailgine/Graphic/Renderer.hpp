#pragma once

#include "Snailgine/Graphic/RenderCommand.hpp"

namespace sn
{
	class Renderer
	{
	 public:
		static void Init();

		static void ShutDown();

		static void BeginScene();

		static void EndScene();

		static void Submit();

		static GraphicAPI GetAPI();
	};
}
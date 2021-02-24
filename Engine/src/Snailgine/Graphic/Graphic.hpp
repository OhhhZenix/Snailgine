#pragma once

#include "Snailgine/PCH.hpp"

namespace sn
{
	enum class GraphicAPI
	{
		OpenGL
	};

	class Graphic {
	 private:
		static GraphicAPI s_API;

	 public:
		virtual ~Graphic() = default;

		virtual void Init() = 0;

		virtual void SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height) = 0;

		virtual void SetClearColor(float p_R, float p_G, float p_B, float p_A) = 0;

		virtual void Clear() = 0;

		static GraphicAPI GetAPI();

		static Graphic* Create();
	};
}
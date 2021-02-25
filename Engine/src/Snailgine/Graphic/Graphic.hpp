#pragma once

#include "Snailgine/Core/Base.hpp"

namespace sn
{
	enum class GraphicAPI
	{
		None = 0,
		OpenGL,
		Vulkan,
	};

	class Graphic
	{
	 private:
		static GraphicAPI s_API;

	 public:
		static Graphic* Create();

		virtual ~Graphic() = default;

		static GraphicAPI GetAPI();

		virtual void Init() = 0;

		virtual void SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height) = 0;

		virtual void SetClearColor(float p_R, float p_G, float p_B, float p_A) = 0;

		virtual void Clear() = 0;
	};
}
#pragma once

#include "Snailgine/Graphic/Graphic.hpp"

namespace sn {
	class RenderCommand {
	 private:
		static Graphic* s_Graphic;

	 public:
		static void Init();

		static void SetViewport(uint32_t p_X, uint32_t p_Y, uint32_t p_Width, uint32_t p_Height);

		static void SetClearColor(float p_R, float p_G, float p_B, float p_A);

		static void Clear();
	};
}
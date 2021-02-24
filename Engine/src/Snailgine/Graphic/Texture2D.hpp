#pragma once

#include "Snailgine/Graphic/Texture.hpp"

namespace sn
{
	class Texture2D : public Texture
	{
	 public:
		static Texture2D* Create(uint32_t p_Width, uint32_t p_Height);

		static Texture2D* Create(const std::string& p_Path);
	};
}
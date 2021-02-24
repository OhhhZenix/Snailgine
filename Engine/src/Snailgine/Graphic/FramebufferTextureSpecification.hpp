#pragma once

#include "Snailgine/Graphic/FramebufferTextureFormat.hpp"

namespace sn
{
	// TODO: filtering/wrap
	class FramebufferTextureSpecification
	{
	 public:
		FramebufferTextureFormat  TextureFormat;

		explicit FramebufferTextureSpecification(FramebufferTextureFormat p_Format = FramebufferTextureFormat::None);
	};
}
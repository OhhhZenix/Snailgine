#pragma once

#include "Snailgine/PCH.hpp"
#include "Snailgine/Graphic/FramebufferAttachmentSpecification.hpp"

namespace sn
{
	struct FramebufferSpecification
	{
		uint32_t Width = 0;
		uint32_t Height = 0;
		uint32_t Samples = 1;
		bool SwapChainTarget = false;
		FramebufferAttachmentSpecification Attachments;
	};
}
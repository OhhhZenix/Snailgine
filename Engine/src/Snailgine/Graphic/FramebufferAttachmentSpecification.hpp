#pragma once

#include "Snailgine/Graphic/FramebufferTextureSpecification.hpp"

namespace sn
{
	class FramebufferAttachmentSpecification
	{
	 public:
		std::vector<FramebufferTextureSpecification> Attachments;

		FramebufferAttachmentSpecification() = default;

		FramebufferAttachmentSpecification(std::initializer_list<FramebufferTextureSpecification> p_Attachments);
	};
}
#include "FramebufferAttachmentSpecification.hpp"

namespace sn
{
	FramebufferAttachmentSpecification::FramebufferAttachmentSpecification(std::initializer_list<
		FramebufferTextureSpecification> p_Attachments)
	{
		Attachments = p_Attachments;
	}
}
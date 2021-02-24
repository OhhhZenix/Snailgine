#pragma once

#include "FramebufferSpecification.hpp"

namespace sn
{
	class Framebuffer
	{
	 public:
		static Framebuffer* Create(const FramebufferSpecification& p_Specification);

		virtual ~Framebuffer() = default;

		virtual void Bind() = 0;

		virtual void Unbind() = 0;

		virtual void Resize(uint32_t p_Width, uint32_t p_Height) = 0;

		[[nodiscard]] virtual uint32_t GetColorAttachmentRendererID(uint32_t p_Index = 0) const = 0;

		[[nodiscard]] virtual const FramebufferSpecification& GetSpecification() const = 0;
	};
}
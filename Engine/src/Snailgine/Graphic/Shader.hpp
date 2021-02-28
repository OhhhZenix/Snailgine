#pragma once

#include "Snailgine/Core/Base.hpp"

namespace sn
{
	class Shader
	{
	 public:
		static Shader* Create(const std::string& p_VertexSource, const std::string& p_FragmentSource);

		virtual ~Shader() = default;

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;
	};
}
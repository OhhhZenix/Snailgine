#pragma once

#include <Snailgine/PCH.hpp>
#include "Snailgine/Graphic/ShaderDataType.hpp"

namespace sn
{
	class BufferElement
	{
	 public:
		std::string Name;
		ShaderDataType Type;
		uint32_t Size;
		size_t Offset;
		bool Normalized;

		BufferElement();

		BufferElement(ShaderDataType p_Type, const std::string& p_Name, bool p_Normalized = false);

		[[nodiscard]] uint32_t GetComponentCount() const;
	};
}